#include "state44.h"
#include "../symbols/SymbolUnterminal.h"

State44::State44() : State("44") {
}

State44::~State44() {
}

bool State44::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R8 : C  →  C , id = val
         * ; | R8
         */
        case SU_SEMICOLON:
            automaton.reduction(5, new SymbolUnterminal(UT_C));
            return true;

        /*
         * , | R8
         */
        case SU_COMMA:
            automaton.reduction(5, new SymbolUnterminal(UT_C));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}