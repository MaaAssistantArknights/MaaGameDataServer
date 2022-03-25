#pragma once

#include <string>
#include <sstream>
#include <memory>

#include <json/json.h>

inline void SetEmitUtf8(bool enable) {
  Json::Value def;
  def["emitUTF8"] = true;
  Json::CharReaderBuilder::setDefaults(&def);
  Json::StreamWriterBuilder::setDefaults(&def);
}

inline std::string toString(const Json::Value& json) {
  Json::StreamWriterBuilder builder;
  std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
  std::ostringstream stream;
  writer->write(json, &stream);
  return stream.str();
}

inline Json::Value fromString(const std::string& sJson) {
  Json::Reader reader;
  Json::Value root;
  return reader.parse(sJson, root) ? root : Json::Value::null;
}