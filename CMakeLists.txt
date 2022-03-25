cmake_minimum_required(VERSION 3.5)

project(MaaGameDataServer)

file(GLOB_RECURSE SRC_FILES src/*.cc)

set(CMAKE_CXX_STANDARD 17)

# fmt 格式化字符串库
add_subdirectory(thirdparty/fmt)

# spdlog 日志库
set(SPDLOG_FMT_EXTERNAL ON)
add_subdirectory(thirdparty/spdlog)

# drogon 网络库
set(BUILD_CTL OFF)
set(BUILD_EXAMPLES OFF)
add_subdirectory(thirdparty/drogon)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE src src/model/gamedata)

target_include_directories(${PROJECT_NAME} PRIVATE
  thirdparty/spdlog/include
  thirdparty/fmt/include
  thirdparty/drogon/lib/inc
  thirdparty/drogon/nosql_lib/redis/inc
  thirdparty/drogon/orm_lib/inc
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
  fmt
  drogon
  spdlog
)
