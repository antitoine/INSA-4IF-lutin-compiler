#include "state13.h"
#include "state23.h"


State13::State13()
        :State("")
{
}

State13::~State13()
{
}


bool State13::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * ; : E23
         * , : E24
         */

        // TODO : implements missing symbols

        case SU_SEMICOLON:
            automaton.transition(symbol, new State23());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}