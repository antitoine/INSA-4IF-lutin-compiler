#include "state23.h"
#include "state3.h"
#include "../symbols/SymbolUnterminal.h"

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
            automaton.reduction(3, new SymbolUnterminal(UT_D_PRIM));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}