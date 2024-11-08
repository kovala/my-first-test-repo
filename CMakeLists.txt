cmake_minimum_required(VERSION 3.28)
project(algo-xp)

set(CMAKE_CXX_STANDARD 23)
set_target_properties(${TARGET}
  PROPERTIES
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED ON
)
#set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package(nlohmann_json)
find_package(argh)
find_package(fmt)


file(GLOB_RECURSE SOURCES
  main.cpp
  i/
  common/*.cpp
  arrays/*.cpp
  dp/**/*.cpp
  trees/**/*.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ./i)
#target_include_directories(${PROJECT_NAME} PRIVATE ./mod/mitata/src)

target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} argh)
target_link_libraries(${PROJECT_NAME} fmt::fmt)
