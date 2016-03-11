#include "state21.h"
#include "../symbols/SymbolUnterminal.h"

State21::State21() : State("21") {
}

State21::~State21() {
}

bool State21::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R12 : I' → lire id
         * id | R21
         * lire | R21
         * ecrire | R21
         * $ | R21
         */
        case S_VARIABLE:
        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
        case SU_DOLLAR:
            automaton.reduction(2, new SymbolUnterminal(UT_I_PRIM));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}