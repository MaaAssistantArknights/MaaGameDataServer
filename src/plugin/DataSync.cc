/**
 *
 *  DataSync.cc
 *
 */

#include "DataSync.h"

using namespace std::chrono_literals;
using namespace drogon::orm;
using namespace drogon_model::MaaGameData;

void DataSync::initAndStart(const Json::Value &config) {
  /// Initialize and start the plugin
  worker_ = std::thread([this] {
    trantor::EventLoop loop;
    loop_ = &loop;
    doSync();
    loop.loop();
  });
}

void DataSync::doSync() {
  std::ifstream ifs(
      "./repo/ArknightsGameData/zh_CN/gamedata/excel/activity_table.json");
  Json::Reader reader;
  Json::Value root;
  auto success = reader.parse(ifs, root);
  if (success) {
    auto data = root.get("basicInfo", Json::Value::null);
    auto keys = data.getMemberNames();
    for (const auto &key : keys) {
      auto value = data.get(key, Json::Value());
      if (!value.isNull()) {
        Mapper<Activity> mp(drogon::app().getDbClient("gamedata"));
        // value["id"] = key;
        // value["tagList"] = "[]";
        value["ungroupedMedalIds"] = toString(value["ungroupedMedalIds"]);
        try {
          auto obj = mp.findByPrimaryKey(key);
          obj.updateByJson(value);
          mp.update(obj);
          std::cout << "updated Activity: " << key << "\n";
        } catch (const UnexpectedRows &) {
          Activity obj(value);
          mp.insert(obj);
          std::cout << "inserted Activity: " << key << "\n";
        } catch (const DrogonDbException &ex) {
          std::cerr << ex.base().what() << "\n";
        }
      }
    }
  } else {
    std::cerr << "Json parse error";
  }
  auto cronexpr = cron::make_cron("0 30 4,16 * * *");
  auto now = time(nullptr);
  auto diff = cron::cron_next(cronexpr, now) - now;
  loop_->runAfter(std::chrono::seconds(diff), [this] { doSync(); });
  std::cout << "Timer added\n";
}

void DataSync::shutdown() {
  /// Shutdown the plugin
  if (loop_) {
    loop_->quit();
    if (worker_.joinable())
      worker_.join();
  }
}
