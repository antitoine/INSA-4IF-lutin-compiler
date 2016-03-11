#include "state13.h"
#include "state23.h"
#include "state24.h"

State13::State13() : State("13") {

}

State13::~State13() {

}


bool State13::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * ; : E23
         */

        case SU_SEMICOLON:
            automaton.transition(symbol, new State23());
            return true;

        /*
        * , : E24
        */
        case SU_COMMA:
            automaton.transition(symbol, new State24());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}