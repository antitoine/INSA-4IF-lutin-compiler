#include "state34.h"
#include "../symbols/SymbolUnterminal.h"

State34::State34() : State("34") {
}

State34::~State34() {
}

bool State34::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R14 : I' -> id := E
         * id     | R14
         * lire   | R14
         * ecrire | R14
         * $      | R14
         */

        case S_VARIABLE:
        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
        case SU_DOLLAR:
            automaton.reduction(4, new SymbolUnterminal(UT_I_PRIM));
            return true;


        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}