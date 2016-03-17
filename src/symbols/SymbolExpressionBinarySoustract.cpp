//#include <boost>
#include <map>
#include "SymbolExpressionBinarySoustract.h"

using namespace std;

SymbolExpressionBinarySoustract::SymbolExpressionBinarySoustract() : SymbolExpressionBinary(S_EXPRESSION_BIN_SUB) {

}

float SymbolExpressionBinarySoustract::eval(map<string, StructVar*>& dicoVariables){
    return firstOperand->eval(dicoVariables) - secondOperand->eval(dicoVariables);
}
