cmake_minimum_required(VERSION 2.8.3)
project(lut)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCE_FILES src/*.h src/*.cpp)

include_directories(lib/re2)

set(LIB_RE2 ${CMAKE_CURRENT_SOURCE_DIR}/lib/re2)

add_executable(lut ${SOURCE_FILES})

target_link_libraries(lut ${LIB_RE2}/libre2.a pthread)

# Coment this line to skip tests after build
add_custom_command(TARGET lut POST_BUILD COMMAND ln -fs ${lut_BINARY_DIR}/lut lut COMMAND bash mktest.sh WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests COMMENT "Run tests ...")
