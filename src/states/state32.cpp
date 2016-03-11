#include "state32.h"
#include "state18.h"
#include "state19.h"
#include "state20.h"
#include "state41.h"

State32::State32() : State("32") {
}

State32::~State32() {
}

bool State32::transition(Automaton &automaton, Symbol *symbol) {
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
             * E : E40
             */

        case UT_E:
            automaton.transition(symbol, new State41());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}