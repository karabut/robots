cmake_minimum_required(VERSION 3.17)
project(test_template)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/google_tests)

include_directories(lib/googletest/include)
include_directories(lib/googlemock/include)

add_executable(test_template tests.cpp main.cpp Map.cpp Robot.cpp)

target_link_libraries(test_template gtest gtest_main)
target_link_libraries(test_template gmock gmock_main)