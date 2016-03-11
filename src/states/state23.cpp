#include "state23.h"
#include "../symbols/SymbolUnterminal.h"

State23::State23() : State("23") {
}

State23::~State23() {
}

bool State23::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R4 : D’ → var V ;
         * var | R4
         */
        case S_DECLARATION_VAR:
            automaton.reduction(3, new SymbolUnterminal(UT_D_PRIM));
            return true;

        /*
         * const | R4
         */
        case S_DECLARATION_CONST:
            automaton.reduction(3, new SymbolUnterminal(UT_D_PRIM));
            return true;

        /*
         * id | R4
         */
        case S_VARIABLE:
            automaton.reduction(3, new SymbolUnterminal(UT_D_PRIM));
            return true;

        /*
         * lire | R4
         */
        case S_INSTRUCTION_READ:
            automaton.reduction(3, new SymbolUnterminal(UT_D_PRIM));
            return true;

        /*
         * ecrire | R4
         */
        case S_INSTRUCTION_WRITE:
            automaton.reduction(3, new SymbolUnterminal(UT_D_PRIM));
            return true;


        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}