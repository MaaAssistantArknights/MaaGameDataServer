#include <drogon/drogon.h>

int main() { drogon::app().loadConfigFile("config/server.json").run(); }