cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(training)
file(GLOB SOURCES
    *.h
    src/*.cpp
)

SET(CMAKE_CXX_FLAGS "-std=c++11")   
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/../cxxtest-4.3)

add_executable (int256 src/int256.cpp src/main.cpp)
add_executable (test_int256 src/int256.cpp test/runner.cpp)
