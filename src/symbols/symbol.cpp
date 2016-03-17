#include "symbol.h"
#include <iostream>
#include <string>

std::string Symbol::toString() {
    std::cout << "Symbol : " << id << std::endl;
}

int Symbol::getId() const {
    return id;
}

void Symbol::execute(map<string, StructVar*>& dicoVariables) {

}

bool Symbol::isPersistent() const {
    return false;
}