//#include <boost>
#include <map>
#include "SymbolExpressionBinaryMultiplication.h"

SymbolExpressionBinaryMultiplication::SymbolExpressionBinaryMultiplication() : SymbolExpressionBinary(S_EXPRESSION_BIN_MUL) {

}

float SymbolExpressionBinaryMultiplication::eval(std::map<Symbol*, StructVar> & dicoVariables){
    return firstOperand->eval(dicoVariables) * secondOperand->eval(dicoVariables);
}
