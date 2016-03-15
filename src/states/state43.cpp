#include "state43.h"
#include "state44.h"

State43::State43() : State("43") {
}

State43::~State43() {
}

bool State43::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * val : E44
         */
        case S_NUMBER:
            automaton.addConstantValueToCurrentDeclarationConst((SymbolNumber *) symbol);
            automaton.transition(symbol, new State44());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}