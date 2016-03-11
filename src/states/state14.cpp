#include "state14.h"
#include "../symbols/SymbolUnterminal.h"

State14::State14() : State("14") {

}

State14::~State14() {

}


bool State14::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R7 : V → id
         * ; | R7
         */
        case SU_SEMICOLON:
            automaton.reduction(1, new SymbolUnterminal(UT_V));
            return true;

        /*
        * , | R7
        */
        case SU_COMMA:
            automaton.reduction(1, new SymbolUnterminal(UT_V));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}