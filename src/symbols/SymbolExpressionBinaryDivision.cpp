#include <map>
#include <cmath>
#include "../exceptions/ErrorSemanticDivisionZero.h"
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

float SymbolExpressionBinaryDivision::eval(map<string, StructVar *> &dicoVariables) {
    float denominator = secondOperand->eval(dicoVariables);

    if (denominator == 0) {
        throw ErrorSemanticDivisionZero(secondOperand->getNumLineDetection(), secondOperand->getNumCharDetection());
    }

    return firstOperand->eval(dicoVariables) / denominator;
}

SymbolExpression *SymbolExpressionBinaryDivision::optimizeExpression(map<string, StructVar *> &dicoVariables) {
    SymbolExpression *exprOptimized = SymbolExpressionBinary::optimizeExpression(dicoVariables);

    if (exprOptimized != NULL) {
        return exprOptimized;
    }

    if (firstOperand->eval(dicoVariables) == 0 && firstOperand->getId() == S_NUMBER) {
        return (new SymbolNumber(0.0));
    } else if (secondOperand->eval(dicoVariables) == 1) {
        return firstOperand;
    } else {
        return this;
    }
}
