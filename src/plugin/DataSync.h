/**
 *
 *  DataSync.h
 *
 */

#pragma once

#include <chrono>
#include <drogon/HttpClient.h>
#include <drogon/drogon.h>
#include <drogon/plugins/Plugin.h>
#include <memory>
#include <thread>
#include <util/croncpp.h>

#include "Character.h"

class DataSync : public drogon::Plugin<DataSync> {
public:
  DataSync() {}
  /// This method must be called by drogon to initialize and start the plugin.
  /// It must be implemented by the user.
  virtual void initAndStart(const Json::Value &config) override;

  /// This method must be called by drogon to shutdown the plugin.
  /// It must be implemented by the user.
  virtual void shutdown() override;

  void doSync();

private:
  trantor::EventLoop* loop_ = nullptr;
  std::thread worker_;
};
