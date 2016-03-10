//#include <boost>
#include <map>
#include <iostream>
#include "SymbolDeclaration.h"

using namespace std;

SymbolDeclaration::SymbolDeclaration(enum symbolIdTable idSymbol):Symbol(idSymbol)
{

}

SymbolDeclaration::SymbolDeclaration():Symbol(S_DECLARATION) {

}

std::string SymbolDeclaration::toString() {
    std::cout << "Symbol D" << std::endl;
}
