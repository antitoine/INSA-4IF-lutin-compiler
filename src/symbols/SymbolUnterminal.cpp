#include <iostream>
#include <sstream>
#include "SymbolUnterminal.h"

SymbolUnterminal::SymbolUnterminal(enum TypeSymbolUnterminal uSymbol):Symbol(uSymbol)
{

}

SymbolUnterminal::~SymbolUnterminal() {

}

std::string SymbolUnterminal::toString() const {
    stringstream s;
    s << "Symbol ID (id: " << to_string(id) << ")";
    return s.str();
}


