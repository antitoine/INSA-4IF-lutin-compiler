#include <map>
#include "SymbolExpression.h"


SymbolExpression::SymbolExpression(enum symbolIdTable idSymbol) : Symbol(idSymbol) {

}

bool SymbolExpression::isPersistent() const {
    return true;
}

SymbolExpression::~SymbolExpression() {

}

SymbolExpression * SymbolExpression::optimizeExpression(map<string, StructVar*>& dicoVariables) {
    return this;
}

void SymbolExpression::detachExpressions() {
    // Do nothing by default
}
