//#include <boost>
#include <map>
#include "SymbolExpression.h"


SymbolExpression::SymbolExpression(enum symbolIdTable idSymbol) : Symbol(idSymbol) {

}

bool SymbolExpression::isPersistent() const {
    return true;
}