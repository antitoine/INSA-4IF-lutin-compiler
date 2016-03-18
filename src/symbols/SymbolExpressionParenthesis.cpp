#include <map>
#include "SymbolExpressionParenthesis.h"

using namespace std;

SymbolExpressionParenthesis::SymbolExpressionParenthesis() : SymbolExpression(S_EXPRESSION_PARENTHESIS) {

}

string SymbolExpressionParenthesis::toString() const {
    return "(" + symbolExpression->toString() + ")";
}

float SymbolExpressionParenthesis::eval(map<string, StructVar*>& dicoVariables){
    return symbolExpression->eval(dicoVariables);
}

void SymbolExpressionParenthesis::setExpression(SymbolExpression *expression) {
    symbolExpression = expression;
}
