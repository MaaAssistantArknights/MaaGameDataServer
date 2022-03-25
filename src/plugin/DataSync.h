/**
 *
 *  DataSync.h
 *
 */

#pragma once

#include <chrono>
#include <fstream>
#include <memory>
#include <thread>

#include <drogon/HttpClient.h>
#include <drogon/drogon.h>
#include <drogon/plugins/Plugin.h>
#include <json/json.h>

#include "util/croncpp.h"
#include "util/json.h"

#include "Activity.h"
#include "Characters.h"

class DataSync : public drogon::Plugin<DataSync> {
public:
  DataSync() {}
  /// This method must be called by drogon to initialize and start the plugin.
  /// It must be implemented by the user.
  virtual void initAndStart(const Json::Value &config) override;

  /// This method must be called by drogon to shutdown the plugin.
  /// It must be implemented by the user.
  virtual void shutdown() override;

private:
  void doSync();

  bool syncActivities();
  bool syncCharacters();
  bool syncItems();
  bool syncSkills();
  bool syncStages();
  bool syncZones();

private:
  trantor::EventLoop *loop_ = nullptr;
  std::thread worker_;
};
