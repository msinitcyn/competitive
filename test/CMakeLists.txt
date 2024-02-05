cmake_minimum_required(VERSION 3.11)
project(competitive_test)

set(CMAKE_CXX_STANDARD 11)

file(GLOB TEST_SOURCES src/*.cpp)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE gtest gtest_main)

set(CMAKE_BUILD_TYPE Debug)
