#include "state36.h"
#include "state43.h"

State36::State36() : State("36") {
}

State36::~State36() {
}

bool State36::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * = : E43
         */

        case SYMBOL_UNIT_EQUAL:
            automaton.transition(symbol, new State43());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}