#include "state11.h"
#include "state21.h"

State11::State11() : State("11") {
}

State11::~State11() {
}

bool State11::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * ; : E21
         */
        case SYMBOL_UNIT_SEMICOLON:
            automaton.affectCurrentExpressionToCurrentInstruction();
            automaton.transition(symbol, new State21());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}