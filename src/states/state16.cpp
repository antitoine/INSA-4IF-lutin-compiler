#include "state16.h"
#include "state27.h"

State16::State16() : State("16") {

}

State16::~State16() {

}

bool State16::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * = : E27
         */
        case SU_EQUAL:
            automaton.transition(symbol, new State27());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}