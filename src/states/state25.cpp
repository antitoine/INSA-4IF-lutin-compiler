#include "state25.h"

State25::State25() : State("25") {
}

State25::~State25() {
}

bool State25::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R5 : D’  → const C ;
         * var | R5
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