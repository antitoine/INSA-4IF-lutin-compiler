#include "state20.h"
#include "../symbols/SymbolUnterminal.h"

State20::State20() : State("20") {
}

State20::~State20() {
}

bool State20::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R21 : E  → val
         * ; | R21
         * + | R21
         * - | R21
         * * | R21
         * / | R21
         * ) | R21
         */
        case SU_SEMICOLON:
        case SU_PLUS:
        case SU_MINUS:
        case SU_MULT:
        case SU_DIV:
        case SU_ENDING_PAR:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}