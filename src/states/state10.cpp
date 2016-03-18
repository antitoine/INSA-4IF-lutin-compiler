#include "state10.h"
#include "../symbols/SymbolUnterminal.h"
#include "../symbols/SymbolUnit.h"

State10::State10() : State("10") {
}

State10::~State10() {
}

bool State10::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R10 : I → I I’
         * id     | R10
         * lire   | R10
         * ecrire | R10
         * $      | R10
         */
        case S_VARIABLE:
        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
        case SYMBOL_UNIT_DOLLAR:
            automaton.reduction(2, new SymbolUnterminal(SYMBOL_UNTERMINAL_I));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}