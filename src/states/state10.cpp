#include "state10.h"
#include "../symbols/SymbolUnterminal.h"
#include "../symbols/UnitSymbol.h"

State10::State10() : State("10") {

}

State10::~State10() {

}

bool State10::transition(Automaton automaton, Symbol symbol) {
    switch (symbol->getId()) {

        /*
         * R10 : I → I I’
         * id    | R10
         */
        case S_VARIABLE:
            automaton.reduction(2, new SymbolUnterminal(UT_I));
            return true;

        /*
         * lire  | R10
         */
        case S_INSTRUCTION_READ:
            automaton.reduction(2, new SymbolUnterminal(UT_I));
            return true;

        /*
         * ecrire| R10
         */
        case S_INSTRUCTION_WRITE:
            automaton.reduction(2, new SymbolUnterminal(UT_I));
            return true;

        /*
         * $     | R10
         */
        case SU_DOLLAR:
            automaton.reduction(2, new UnitSymbol(SU_DOLLAR));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}