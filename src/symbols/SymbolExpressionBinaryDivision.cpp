//#include <boost>
#include <map>
#include "SymbolExpressionBinaryDivision.h"

using namespace std;

SymbolExpressionBinaryDivision::SymbolExpressionBinaryDivision() : SymbolExpressionBinary(S_EXPRESSION_BIN_DIV) {

}

float SymbolExpressionBinaryDivision::eval(std::map<Symbol*, StructVar> & dicoVariables){
    return firstOperand->eval(dicoVariables) / secondOperand->eval(dicoVariables);
}