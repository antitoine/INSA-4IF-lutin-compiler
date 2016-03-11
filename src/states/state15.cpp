#include "state15.h"
#include "state25.h"
#include "state26.h"

State15::State15() : State("15") {

}

State15::~State15() {

}

bool State15::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * ; : E25
         */
        case SU_SEMICOLON:
            automaton.transition(symbol, new State25());
            return true;

        /*
        * , : E26
        */
        case SU_COMMA:
            automaton.transition(symbol, new State26());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}