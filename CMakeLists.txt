cmake_minimum_required(VERSION 3.2)
project(lutin_compiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/automaton.cpp src/automaton.h src/states/state.cpp src/states/state.h src/states/state0.cpp src/states/state0.h src/states/state1.cpp src/states/state1.h src/states/state8.cpp src/states/state8.h src/states/state13.cpp src/states/state13.h src/states/state14.cpp src/states/state14.h src/states/state23.cpp src/states/state23.h src/symbols/symbol.cpp src/symbols/symbol.h src/symbols/SymbolInstruction.cpp src/symbols/SymbolInstruction.h src/symbols/SymbolDeclaration.cpp src/symbols/SymbolDeclaration.h src/symbols/UnitSymbol.cpp src/symbols/UnitSymbol.h src/symbols/SymbolInstructionWrite.cpp src/symbols/SymbolInstructionWrite.cpp src/symbols/SymbolInstruction.h src/symbols/SymbolInstruction.cpp src/symbols/SymbolInstructionRead.h src/symbols/SymbolInstructionRead.cpp src/symbols/SymbolDeclarationConst.h src/symbols/SymbolDeclarationConst.cpp src/symbols/SymbolDeclarationVar.h src/symbols/SymbolDeclarationVar.cpp src/symbols/SymbolExpression.h src/symbols/SymbolExpression.cpp src/symbols/SymbolExpressionBinary.h src/symbols/SymbolExpressionBinary.cpp src/symbols/SymbolExpressionParenthesis.h src/symbols/SymbolExpressionParenthesis.cpp src/symbols/SymbolVariable.h src/symbols/SymbolVariable.cpp src/symbols/SymbolNumber.h src/symbols/SymbolNumber.cpp src/symbols/SymbolVariable.h src/symbols/SymbolVariable.cpp src/symbols/SymbolExpressionBinaryAdd.h src/symbols/SymbolExpressionBinaryAdd.cpp src/symbols/SymbolExpressionBinarySoustract.h src/symbols/SymbolExpressionBinarySoustract.cpp src/symbols/SymbolExpressionBinaryMultiplication.h src/symbols/SymbolExpressionBinaryMultiplication.cpp src/symbols/SymbolExpressionBinaryDivision.h src/symbols/SymbolExpressionBinaryDivision.cpp src/Lexer.cpp src/Lexer.h src/symbols/SymbolUnterminal.cpp src/symbols/SymbolUnterminal.h src/TestRegex.cpp src/TestRegex.h)

include_directories(lib/re2)

set(LIB_RE2 ${CMAKE_CURRENT_SOURCE_DIR}/lib/re2)

add_executable(lutin_compiler ${SOURCE_FILES})

target_link_libraries(lutin_compiler ${LIB_RE2}/libre2.a pthread)
