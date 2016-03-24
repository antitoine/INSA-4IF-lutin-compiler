#include <map>
#include "SymbolExpressionBinaryAdd.h"

using namespace std;

SymbolExpressionBinaryAdd::SymbolExpressionBinaryAdd() : SymbolExpressionBinary(S_EXPRESSION_BIN_ADD) {

}

SymbolExpressionBinaryAdd::~SymbolExpressionBinaryAdd() {

}

string SymbolExpressionBinaryAdd::toString() const {
    return firstOperand->toString() + " + " + secondOperand->toString();
}

float SymbolExpressionBinaryAdd::eval(map<string, StructVar*>& dicoVariables){
    return firstOperand->eval(dicoVariables) + secondOperand->eval(dicoVariables);
}

SymbolExpression * SymbolExpressionBinaryAdd::optimizeExpression(map<string, StructVar*>& dicoVariables) {
    SymbolExpressionBinary::optimizeExpression(dicoVariables);

    if (firstOperand->eval(dicoVariables) == 0 && firstOperand->getId() == S_NUMBER) {
        return secondOperand;
    }
    else if (secondOperand->eval(dicoVariables) == 0 && secondOperand->getId() == S_NUMBER) {
        return firstOperand;
    }
    else {
        return this;
    }
}
