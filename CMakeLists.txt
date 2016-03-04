cmake_minimum_required(VERSION 3.3)
project(lutin_compiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/state.cpp src/state.h)
add_executable(lutin_compiler ${SOURCE_FILES})