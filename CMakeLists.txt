cmake_minimum_required(VERSION 3.28)
project(algo-xp)

set(CMAKE_CXX_STANDARD 20)

set_target_properties(${TARGET}
  PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
)

find_package(nlohmann_json)
find_package(argh)
find_package(fmt)

#if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
#  message(STATUS "Compiling on macOS")
#else()
#  add_subdirectory(pauk)
#endif()

file(GLOB_RECURSE SOURCES
  main.cpp
  "arrays/*.cpp"
  "dp/**/*.cpp"
  "trees/**/*.cpp"
)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE i)

target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} argh)
target_link_libraries(${PROJECT_NAME} fmt::fmt)
