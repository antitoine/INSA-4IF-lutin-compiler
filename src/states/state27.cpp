#include "state27.h"
#include "state37.h"

State27::State27() : State("27") {
}

State27::~State27() {
}

bool State27::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * val : E37
         */
        case S_NUMBER:
            automaton.transition(symbol, new State37());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}