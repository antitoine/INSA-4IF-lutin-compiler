#include "state19.h"
#include "../symbols/SymbolUnterminal.h"

State19::State19() : State("19") {

}

State19::~State19() {

}

bool State19::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R20 : E  → id
         * ; | R20
         */
        case SU_SEMICOLON:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        /*
         * + | R20
         */
        case SU_PLUS:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        /*
         * - | R20
         */
        case SU_MINUS:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        /*
         * * | R20
         */
        case SU_MULT:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        /*
         * / | R20
         */
        case SU_DIV:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        /*
         * ) | R20
         */
        case SU_ENDING_PAR:
            automaton.reduction(1, new SymbolUnterminal(UT_E));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}