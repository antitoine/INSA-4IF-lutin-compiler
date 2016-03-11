#include "state5.h"
#include "state11.h"

State5::State5() : State(" 5") {
}

State5::~State5() {
}

bool State5::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

        /*
         * id : E11
         */
        case S_VARIABLE:
            automaton.transition(symbol, new State11());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}