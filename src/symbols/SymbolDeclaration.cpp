#include <map>
#include "SymbolDeclaration.h"

using namespace std;

SymbolDeclaration::SymbolDeclaration() : Symbol(S_DECLARATION) {

}

SymbolDeclaration::SymbolDeclaration(enum symbolIdTable idSymbol) : Symbol(idSymbol) {

}

bool SymbolDeclaration::isPersistent() const {
    return true;
}

void SymbolDeclaration::check(map<string, StructVar *> &dicoVariables) {
    // Double declaration already checked during lexical analysis
}

SymbolDeclaration::~SymbolDeclaration() {

}
