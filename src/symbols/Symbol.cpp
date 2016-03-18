#include "Symbol.h"
#include <iostream>
#include <string>

int Symbol::getId() const {
    return id;
}

void Symbol::execute(map<string, StructVar*>& dicoVariables) {

}

bool Symbol::isPersistent() const {
    return false;
}