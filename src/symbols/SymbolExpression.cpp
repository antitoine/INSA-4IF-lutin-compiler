#include <map>
#include "SymbolExpression.h"

using namespace std;

SymbolExpression::SymbolExpression(enum symbolIdTable idSymbol) : Symbol(idSymbol) {

}

SymbolExpression::~SymbolExpression() {

}

bool SymbolExpression::isPersistent() const {
    return true;
}

SymbolExpression * SymbolExpression::optimizeExpression(map<string, StructVar*>& dicoVariables) {
    return this;
}

void SymbolExpression::detachExpressions() {
    // Do nothing by default
}
