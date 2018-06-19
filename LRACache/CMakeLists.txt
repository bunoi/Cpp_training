cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(training_cache)

SET(CMAKE_CXX_FLAGS "-std=c++11")   
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(/home/bb/Cpp_training/cxxtest-4.3)

add_executable (main src/LRACache.cpp src/main.cpp)
