
#include "state.h"
#include "state14.h"
#include "state13.h"

State14::State14()
        :State("")
{
}

State14::~State14()
{
}


bool State14::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R7 : V -> id
         * ; : R7
         * , : R7
         */

        // TODO : implements missing symbols

        case SU_SEMICOLON:
            automaton.reduction(1, new State13());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}