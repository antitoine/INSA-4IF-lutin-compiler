#include "state28.h"
#include "../symbols/SymbolUnterminal.h"

State28::State28() : State("28") {
}

State28::~State28() {
}

bool State28::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R13 : I’ → ecrire E ;
         * id | R13
         */
        case S_VARIABLE:
            automaton.reduction(3, new SymbolUnterminal(UT_I_PRIM));
            return true;

        /*
         * lire | R13
         */
        case S_INSTRUCTION_READ:
            automaton.reduction(3, new SymbolUnterminal(UT_I_PRIM));
            return true;

        /*
         * ecrire | R13
         */
        case S_INSTRUCTION_WRITE:
            automaton.reduction(3, new SymbolUnterminal(UT_I_PRIM));
            return true;

        /*
         * $ | R13
         */
        case SU_DOLLAR:
            automaton.reduction(3, new SymbolUnterminal(UT_I_PRIM));
            return true;


        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}