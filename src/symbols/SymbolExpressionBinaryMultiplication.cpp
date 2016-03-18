#include <map>
#include "SymbolExpressionBinaryMultiplication.h"

using namespace std;

SymbolExpressionBinaryMultiplication::SymbolExpressionBinaryMultiplication() : SymbolExpressionBinary(S_EXPRESSION_BIN_MUL) {

}

string SymbolExpressionBinaryMultiplication::toString() const {
    return firstOperand->toString() + " * " + secondOperand->toString();
}

float SymbolExpressionBinaryMultiplication::eval(map<string, StructVar*>& dicoVariables){
    return firstOperand->eval(dicoVariables) * secondOperand->eval(dicoVariables);
}
