#include "state30.h"
#include "state18.h"
#include "state19.h"
#include "state20.h"
#include "state39.h"

State30::State30() : State("30") {
}

State30::~State30() {
}

bool State30::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * id : E19
         */
        case S_VARIABLE:
            automaton.transition(symbol, new State19());
            return true;

            /*
             * val : E20
             */
        case S_NUMBER:
            automaton.transition(symbol, new State20());
            return true;

            /*
             * ( : E18
             */
        case SU_OPENNING_PAR:
            automaton.transition(symbol, new State18());
            return true;

            /*
             * E : E39
             */
        case UT_E:
            automaton.transition(symbol, new State39());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}