#include "state7.h"
#include "state12.h"

State7::State7() : State(" 7") {
}

State7::~State7() {
}

bool State7::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

        /*
         * := : E12
         */
        case SYMBOL_UNIT_AFFECT:
            automaton.transition(symbol, new State12());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}