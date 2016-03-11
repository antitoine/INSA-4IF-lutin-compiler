//#include <boost>
#include <map>
#include "SymbolExpressionBinaryAdd.h"


SymbolExpressionBinaryAdd::SymbolExpressionBinaryAdd() : SymbolExpressionBinary(S_EXPRESSION_BIN_ADD) {

}

float SymbolExpressionBinaryAdd::eval(std::map<Symbol*, StructVar> & dicoVariables){
    return firstOperand->eval(dicoVariables) + secondOperand->eval(dicoVariables);
}

