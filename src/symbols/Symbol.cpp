#include "Symbol.h"

Symbol::Symbol(int id)
        : id(id), numLineDetection(-1), numCharDetection(-1) {
}

Symbol::~Symbol() {
}

int Symbol::getId() const {
    return id;
}

bool Symbol::isPersistent() const {
    return false;
}

void Symbol::execute(map<string, StructVar *> &dicoVariables) {
    // Nothing to do by default
}

void Symbol::check(map<string, StructVar *> &dicoVariables) {
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

Symbol *Symbol::optimize(map<string, StructVar *> &dicoVariables) {
    // Nothing to optimize by default
    return this;
}
