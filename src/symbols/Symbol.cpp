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
        : id(id), numLineDetection(-1), numCharDetection(-1) {

}

void Symbol::check(map<string, StructVar*>& dicoVariables) {
    // Nothing to check by default
}

void Symbol::setSymbolDetectionPosition(int numLine, int numChar) {
    numLineDetection = numLine;
    numCharDetection = numChar;
}

int Symbol::getNumLineDetection() const {
    return numLineDetection;
}

int Symbol::getNumCharDetection() const {
    return numCharDetection;
}

Symbol::~Symbol() {

}

bool Symbol::canDeleteExprComponents() const {
    return true;
}
