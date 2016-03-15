#include "state35.h"
#include "../symbols/SymbolUnterminal.h"

State35::State35() : State("35") {
}

State35::~State35() {
}

bool State35::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R7 : V -> id
         * ; | R7
         * , | R7
         */

        case SU_SEMICOLON:
        case SU_COMMA:
            automaton.reduction(3, new SymbolUnterminal(UT_V));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}