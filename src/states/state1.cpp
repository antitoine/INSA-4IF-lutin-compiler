#include "state1.h"
#include "state8.h"

State1::State1()
        :State("")
{
}

State1::~State1()
{
}


bool State1::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * var : E8
         * const : E9
         * id : E7
         * lire : E5
         * ecrire : E6
         * D' : E3
         * I : E2
         * I' : E4
         */

            // TODO : implements missing symbols

        case S_DECLARATION_VAR:
            automaton.transition(symbol, new State8());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}