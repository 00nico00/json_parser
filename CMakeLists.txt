cmake_minimum_required(VERSION 3.26)
project(json_parser)

set(CMAKE_CXX_STANDARD 23)

set(TEST_MAIN test)

add_executable(${PROJECT_NAME} main.cpp)

add_executable(${TEST_MAIN} ./test/test_main.cpp)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(${TEST_MAIN} PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)