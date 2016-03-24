#include <map>
#include "SymbolExpressionBinaryDivision.h"
#include "SymbolNumber.h"

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

SymbolExpression * SymbolExpressionBinaryDivision::optimizeExpression(map<string, StructVar*>& dicoVariables) {
    SymbolExpressionBinary::optimizeExpression(dicoVariables);

    if (firstOperand->eval(dicoVariables) == 0 && firstOperand->getId() == S_NUMBER) {
        return (new SymbolNumber(0.0));
    }
    else if (secondOperand->eval(dicoVariables) == 1) {
        return firstOperand;
    }
    else {
        return this;
    }
}
