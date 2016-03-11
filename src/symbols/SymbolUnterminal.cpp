#include <iostream>
#include "SymbolUnterminal.h"

SymbolUnterminal::SymbolUnterminal(enum unterminalSymbolIdTable uSymbol):Symbol(uSymbol)
{
}

std::string SymbolUnterminal::toString() {
    std::cout << "Symbol ID (id: " << id << ")" << std::endl;
}
