cmake_minimum_required(VERSION 3.2)
project(lutin_compiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/state.cpp src/state.h src/symbol.cpp src/symbol.h src/SymbolInstruction.cpp src/SymbolInstruction.h src/SymbolDeclaration.cpp src/SymbolDeclaration.h src/UnitSymbol.cpp src/UnitSymbol.h src/SymbolInstructionwWrite.cpp src/SymbolInstructionwWrite.cpp src/SymbolInstruction.h src/SymbolInstruction.cpp src/SymbolInstructionRead.h src/SymbolInstructionRead.cpp)

add_executable(lutin_compiler ${SOURCE_FILES})
