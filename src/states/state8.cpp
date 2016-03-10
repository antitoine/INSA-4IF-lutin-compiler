#include "state8.h"
#include "state14.h"

State8::State8()
        :State("")
{
}

State8::~State8()
{
}


bool State8::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * id : E14
         * V : E13
         */

        // TODO : implements missing symbols

        case S_VARIABLE:
            automaton.transition(symbol, new State14());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}