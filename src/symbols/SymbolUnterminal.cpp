#include <iostream>
#include "SymbolUnterminal.h"

SymbolUnterminal::SymbolUnterminal(enum TypeSymbolUnterminal uSymbol):Symbol(uSymbol)
{

}

std::string SymbolUnterminal::toString() const {
    return "Symbol ID (id: " + to_string(id) + ")";
}
