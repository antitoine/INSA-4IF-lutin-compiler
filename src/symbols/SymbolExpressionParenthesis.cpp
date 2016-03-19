#include <map>
#include <sstream>
#include "SymbolExpressionParenthesis.h"

using namespace std;

SymbolExpressionParenthesis::SymbolExpressionParenthesis() : SymbolExpression(S_EXPRESSION_PARENTHESIS) {

}

string SymbolExpressionParenthesis::toString() const {
    stringstream s;
    s << "(" << symbolExpression->toString() << ")";
    return s.str();
}

float SymbolExpressionParenthesis::eval(map<string, StructVar*>& dicoVariables){
    return symbolExpression->eval(dicoVariables);
}

void SymbolExpressionParenthesis::setExpression(SymbolExpression *expression) {
    symbolExpression = expression;
}

list<Error *> * SymbolExpressionParenthesis::checkEval(map<string, StructVar*>& dicoVariables) {
    return symbolExpression->checkEval(map<string, StructVar*>& dicoVariables);
}
