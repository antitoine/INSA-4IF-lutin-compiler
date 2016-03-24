#include <map>
#include "SymbolExpressionBinaryMultiplication.h"
#include "SymbolNumber.h"

using namespace std;

SymbolExpressionBinaryMultiplication::SymbolExpressionBinaryMultiplication() : SymbolExpressionBinary(S_EXPRESSION_BIN_MUL) {

}

SymbolExpressionBinaryMultiplication::~SymbolExpressionBinaryMultiplication() {

}

string SymbolExpressionBinaryMultiplication::toString() const {
    return firstOperand->toString() + " * " + secondOperand->toString();
}

float SymbolExpressionBinaryMultiplication::eval(map<string, StructVar*>& dicoVariables){
    return firstOperand->eval(dicoVariables) * secondOperand->eval(dicoVariables);
}

SymbolExpression * SymbolExpressionBinaryMultiplication::optimizeExpression(map<string, StructVar*>& dicoVariables) {
    SymbolExpression * exprOptimized = SymbolExpressionBinary::optimizeExpression(dicoVariables);

    if (exprOptimized != NULL) {
        return exprOptimized;
    }

    if (firstOperand->eval(dicoVariables) == 1) {
        return secondOperand;
    }
    else if (firstOperand->eval(dicoVariables) == 0 && firstOperand->getId() == S_NUMBER) {
        return (new SymbolNumber(0.0));
    }
    else if (secondOperand->eval(dicoVariables) == 1) {
        return firstOperand;
    }
    else if (secondOperand->eval(dicoVariables) == 0 && secondOperand->getId() == S_NUMBER) {
        return (new SymbolNumber(0.0));
    }
    else {
        return this;
    }
}

