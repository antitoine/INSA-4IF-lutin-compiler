#include "state23.h"
#include "state3.h"

State23::State23()
        :State("")
{
}

State23::~State23()
{
}


bool State23::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R4 : D’  -> var V ;
         * var : R4
         * const : R4
         * id : R4
         * lire : R4
         * ecrire : R4
         */

        // TODO : implements missing symbols

        case SU_SEMICOLON:
            // TODO
            //automaton.reduction(3, new State3());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}