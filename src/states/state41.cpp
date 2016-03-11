#include "state41.h"
#include "../symbols/SymbolUnterminal.h"

State41::State41() : State("41") {
}

State41::~State41() {
}

bool State41::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {


        /*
         * R18 : E  → E / E
         * ; | R18
         */
        case SU_SEMICOLON:
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

        /*
         * + | R18
         */
        case SU_PLUS:
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

        /*
         * - | R18
         */
        case SU_MINUS:
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

        /*
         * * | R18
         */
        case SU_MULT:
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

        /*
         * / | R18
         */
        case SU_DIV:
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

        /*
        * ) | R18
        */
        case SU_ENDING_PAR:
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;


        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}