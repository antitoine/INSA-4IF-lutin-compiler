#include "state18.h"
#include "state18.h"
#include "state19.h"
#include "state20.h"
#include "state33.h"

State18::State18() : State("18") {

}

State18::~State18() {

}

bool State18::transition(Automaton & automaton, Symbol * symbol) {
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
         * E : E33
         */
        case UT_E:
            automaton.transition(symbol, new State33());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}