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

void Symbol::execute(map<Symbol*, StructVar> & dicoVariables) {

}

bool Symbol::isPersistent() const {
    return false;
}