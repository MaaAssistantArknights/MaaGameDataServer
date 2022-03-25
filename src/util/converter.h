#pragma once

#include <memory>

#include "json.h"

namespace converter {
namespace json {
template <typename T> inline void AfterDbRead(std::shared_ptr<T> &ptr) {
  *ptr = fromString(*ptr);
}

template <typename T> inline void BeforeDbWrite(std::shared_ptr<T> &ptr) {
  *ptr = toString(*ptr);
}
} // namespace json
} // namespace converter