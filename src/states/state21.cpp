#include "state21.h"
#include "../symbols/SymbolUnterminal.h"

State21::State21() : State("21") {
}

State21::~State21() {
}

bool State21::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R12 : I' → lire id ;
         * id | R12
         * lire | R12
         * ecrire | R12
         * $ | R12
         */
        case S_VARIABLE:
        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
        case SU_DOLLAR:
            automaton.reduction(3, new SymbolUnterminal(UT_I_PRIM));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}