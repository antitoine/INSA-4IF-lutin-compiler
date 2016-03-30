#include <map>
#include "SymbolExpressionBinarySubstract.h"

using namespace std;

SymbolExpressionBinarySubstract::SymbolExpressionBinarySubstract() : SymbolExpressionBinary(S_EXPRESSION_BIN_SUB) {

}

SymbolExpressionBinarySubstract::~SymbolExpressionBinarySubstract() {

}

string SymbolExpressionBinarySubstract::toString() const {
    return firstOperand->toString() + " - " + secondOperand->toString();
}

float SymbolExpressionBinarySubstract::eval(map<string, StructVar *> &dicoVariables) {
    return firstOperand->eval(dicoVariables) - secondOperand->eval(dicoVariables);
}

SymbolExpression *SymbolExpressionBinarySubstract::optimizeExpression(map<string, StructVar *> &dicoVariables) {
    SymbolExpression *exprOptimized = SymbolExpressionBinary::optimizeExpression(dicoVariables);

    if (exprOptimized != NULL) {
        return exprOptimized;
    }

    if (secondOperand->eval(dicoVariables) == 0 && secondOperand->getId() == S_NUMBER) {
        return firstOperand;
    } else {
        return this;
    }
}
