#include <map>
#include "SymbolExpressionBinaryDivision.h"

using namespace std;

SymbolExpressionBinaryDivision::SymbolExpressionBinaryDivision() : SymbolExpressionBinary(S_EXPRESSION_BIN_DIV) {

}

SymbolExpressionBinaryDivision::~SymbolExpressionBinaryDivision() {

}

string SymbolExpressionBinaryDivision::toString() const {
    return firstOperand->toString() + " / " + secondOperand->toString();
}

float SymbolExpressionBinaryDivision::eval(map<string, StructVar*>& dicoVariables){
    return firstOperand->eval(dicoVariables) / secondOperand->eval(dicoVariables);
}

