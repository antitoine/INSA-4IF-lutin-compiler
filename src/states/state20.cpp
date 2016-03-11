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
         */
        case SU_SEMICOLON:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        /*
         * + | R21
         */
        case SU_PLUS:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        /*
         * - | R21
         */
        case SU_MINUS:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        /*
         * * | R21
         */
        case SU_MULT:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        /*
         * / | R21
         */
        case SU_DIV:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        /*
         * ) | R21
         */
        case SU_ENDING_PAR:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}