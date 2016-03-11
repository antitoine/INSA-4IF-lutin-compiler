#include "state14.h"
#include "state23.h"
#include "state24.h"

State14::State14() : State("14") {

}

State14::~State14() {

}


bool State14::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R7 : V → id
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