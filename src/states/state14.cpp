#include "state14.h"
#include "../symbols/SymbolUnterminal.h"

State14::State14() : State("14") {
}

State14::~State14() {
}


bool State14::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R7 : V → id
         * ; | R7
         * , | R7
         */
        case SYMBOL_UNIT_SEMICOLON:
        case SYMBOL_UNIT_COMMA:
            automaton.reduction(1, new SymbolUnterminal(SYMBOL_UNTERMINAL_V));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}