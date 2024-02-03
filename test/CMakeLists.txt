cmake_minimum_required(VERSION 3.11)
project(competitive_test)

set(CMAKE_CXX_STANDARD 11)

add_executable(dsu_test src/dsu_test.cpp)
target_link_libraries(dsu_test PRIVATE gtest gtest_main)

add_executable(kmp_test src/kmp_test.cpp)
target_link_libraries(kmp_test PRIVATE gtest gtest_main)

set(CMAKE_BUILD_TYPE Debug)
