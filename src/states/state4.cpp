#include "state4.h"
#include "../symbols/SymbolUnterminal.h"

State4::State4() : State(" 4") {
}

State4::~State4() {
}

bool State4::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

        /*
         * R11 : I -> I'
         * id     | R11
         * lire   | R11
         * ecrire | R11
         * $      | R11
         */
        case S_VARIABLE:
        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
        case SU_DOLLAR:
            automaton.reduction(1, new SymbolUnterminal(UT_I));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}