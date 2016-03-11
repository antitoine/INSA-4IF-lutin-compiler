#include "state37.h"
#include "../symbols/SymbolUnterminal.h"

State37::State37() : State("37") {
}

State37::~State37() {
}

bool State37::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R9 : C -> id = val
         * ; | R9
         * , | R9
         */

        case SU_SEMICOLON:
        case SU_COMMA:
            automaton.reduction(3, new SymbolUnterminal(UT_C));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}