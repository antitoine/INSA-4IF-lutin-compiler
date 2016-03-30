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

float SymbolExpressionBinaryAdd::eval(map<string, StructVar *> &dicoVariables) {
    return firstOperand->eval(dicoVariables) + secondOperand->eval(dicoVariables);
}

SymbolExpression *SymbolExpressionBinaryAdd::optimizeExpression(map<string, StructVar *> &dicoVariables) {
    SymbolExpression *exprOptimized = SymbolExpressionBinary::optimizeExpression(dicoVariables);

    if (exprOptimized != NULL) {
        return exprOptimized;
    }

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
