cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(training)
file(GLOB SOURCES
    *.h
    *.cpp
)

SET(CMAKE_CXX_FLAGS "-std=c++11")   
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories("E:/Band Protocol/cxxtest-4.4")
add_executable (int256 src/int256.cpp src/main.cpp)