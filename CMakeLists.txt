cmake_minimum_required(VERSION 3.26)
project(json_parser)

set(CMAKE_CXX_STANDARD 23)

include_directories(./include)

set(SRCS
        src/main.cpp
)
set(HEADERS
        include/JsonParser.hpp
)


add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS})

add_executable(Test
        test/main.cpp)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(Test PRIVATE GTest::gtest GTest::gtest_main)