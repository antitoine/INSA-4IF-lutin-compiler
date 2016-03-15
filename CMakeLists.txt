cmake_minimum_required(VERSION 3.2)
project(lutin_compiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCE_FILES src/*.h src/*.cpp)

include_directories(lib/re2)

set(LIB_RE2 ${CMAKE_CURRENT_SOURCE_DIR}/lib/re2)

add_executable(lutin_compiler ${SOURCE_FILES} src/StructVar.h)

target_link_libraries(lutin_compiler ${LIB_RE2}/libre2.a pthread)
