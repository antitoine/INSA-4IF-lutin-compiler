#include "symbol.h"
#include <iostream>
#include <string>

std::string Symbol::toString() {
    std::cout << "Symbol : " << id << std::endl;
}

int Symbol::getId() const {
    return id;
}

void Symbol::computeSublistSymbols(const std::list<Symbol*> & symbolsToCompute) {
    // Default: ignore
    return;
}