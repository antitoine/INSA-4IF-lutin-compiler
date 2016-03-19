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

Symbol::Symbol(int id)
        : id(id) {

}

void Symbol::check(map<string, StructVar*>& dicoVariables) {
    // Nothing to check by default
}
