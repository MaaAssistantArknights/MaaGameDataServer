#include <drogon/drogon.h>
#include "util/json.h"

int main() {
  SetEmitUtf8(true);
  drogon::app().loadConfigFile("config/server.json").run();
}