cmake_minimum_required(VERSION 3.2)
project(lutin_compiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/state.cpp src/state.h src/symbol.cpp src/symbol.h src/SymbolInstruction.cpp src/SymbolInstruction.h src/SymbolDeclaration.cpp src/SymbolDeclaration.h src/UnitSymbol.cpp src/UnitSymbol.h src/SymbolInstructionWrite.cpp src/SymbolInstructionWrite.cpp src/SymbolInstruction.h src/SymbolInstruction.cpp src/SymbolInstructionRead.h src/SymbolInstructionRead.cpp src/SymbolDeclarationConst.h src/SymbolDeclarationConst.cpp src/SymbolDeclarationVar.h src/SymbolDeclarationVar.cpp src/SymbolExpression.h src/SymbolExpression.cpp src/SymbolExpressionBinary.h src/SymbolExpressionBinary.cpp src/SymbolExpressionParenthesis.h src/SymbolExpressionParenthesis.cpp  src/SymbolVariable.h src/SymbolVariable.cpp src/SymbolNumber.h src/SymbolNumber.cpp src/SymbolVariable.h src/SymbolVariable.cpp src/SymbolExpressionBinaryAdd.h src/SymbolExpressionBinaryAdd.cpp src/SymbolExpressionBinarySoustract.h src/SymbolExpressionBinarySoustract.cpp src/SymbolExpressionBinaryMultiplication.h src/SymbolExpressionBinaryMultiplication.cpp src/SymbolExpressionBinaryDivision.h src/SymbolExpressionBinaryDivision.cpp src/Lexer.cpp src/Lexer.h)

add_executable(lutin_compiler ${SOURCE_FILES})
