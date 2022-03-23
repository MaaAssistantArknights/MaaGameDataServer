/**
 *
 *  DataSync.cc
 *
 */

#include "DataSync.h"

using namespace std::chrono_literals;
using namespace drogon::orm;
using namespace drogon_model::MaaGameData::gamedata;

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
  auto http_client = drogon::HttpClient::newHttpClient(
      "https://raw.githubusercontent.com", drogon::app().getLoop());
  auto request = drogon::HttpRequest::newHttpRequest();
  request->setPath("/Kengxxiao/ArknightsGameData/master/zh_CN/gamedata/"
                   "excel/character_table.json");
  auto [result, response] = http_client->sendRequest(request);
  if (result == drogon::ReqResult::Ok) {
    auto data = response->getJsonObject();
    auto keys = data->getMemberNames();
    for (const auto &key : keys) {
      auto value = data->get(key, Json::Value());
      if (!value.isNull()) {
        Mapper<Character> mp(drogon::app().getDbClient("gamedata"));
        value["id"] = key;
        value["tagList"] = value["tagList"].toStyledString();
        try {
          auto obj = mp.findByPrimaryKey(key);
          obj.updateByJson(value);
          mp.update(obj);
          std::cout << "updated character: " << key << "\n";
        } catch (const UnexpectedRows &) {
          Character obj(value);
          mp.insert(obj);
          std::cout << "inserted character: " << key << "\n";
        } catch (const DrogonDbException& ex) {
          std::cerr << ex.base().what() << "\n";
        }
      }
    }
  } else {
  }

  auto cronexpr = cron::make_cron("0 0 5,17 * * *");
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
