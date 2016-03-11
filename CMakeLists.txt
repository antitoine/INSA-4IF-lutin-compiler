cmake_minimum_required(VERSION 3.2)
project(lutin_compiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCE_FILES src/*.h src/*.cpp)

add_executable( lutin_compiler ${SOURCE_FILES} )