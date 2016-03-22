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

