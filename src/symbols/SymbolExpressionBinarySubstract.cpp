#include <map>
#include "SymbolExpressionBinarySubstract.h"

using namespace std;

SymbolExpressionBinarySubstract::SymbolExpressionBinarySubstract() : SymbolExpressionBinary(S_EXPRESSION_BIN_SUB) {

}

string SymbolExpressionBinarySubstract::toString() const {
    return firstOperand->toString() + " - " + secondOperand->toString();
}

float SymbolExpressionBinarySubstract::eval(map<string, StructVar*>& dicoVariables){
    return firstOperand->eval(dicoVariables) - secondOperand->eval(dicoVariables);
}
