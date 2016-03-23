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
    return symbolExpression->checkEval(dicoVariables);
}

SymbolExpressionParenthesis::~SymbolExpressionParenthesis() {
    if (symbolExpression != NULL) {
        delete symbolExpression;
    }
}

SymbolExpression * SymbolExpressionParenthesis::optimizeExpression(map<string, StructVar*>& dicoVariables) {
    symbolExpression = symbolExpression->optimizeExpression(dicoVariables);

    if (symbolExpression->getId() == S_EXPRESSION_PARENTHESIS || symbolExpression->getId() == S_NUMBER || symbolExpression->getId() == S_VARIABLE)
        return symbolExpression;
    else
        return this;
}
