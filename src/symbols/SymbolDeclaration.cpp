#include <map>
#include <iostream>
#include "SymbolDeclaration.h"

using namespace std;

SymbolDeclaration::SymbolDeclaration(enum symbolIdTable idSymbol):Symbol(idSymbol)
{

}

SymbolDeclaration::SymbolDeclaration():Symbol(S_DECLARATION) {

}

bool SymbolDeclaration::isPersistent() const {
    return true;
}
