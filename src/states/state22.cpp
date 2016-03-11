#include "state22.h"
#include "state34.h"
#include "state29.h"
#include "state31.h"
#include "state30.h"
#include "state32.h"

State22::State22() : State("22") {
}

State22::~State22() {
}

bool State22::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {


        /*
         * ; : E34
         */
        case SU_SEMICOLON:
            automaton.transition(symbol, new State34());
            return true;

        /*
         * + : E29
         */
        case SU_PLUS:
            automaton.transition(symbol, new State29());
            return true;

        /*
         * - : E31
         */
        case SU_MINUS:
            automaton.transition(symbol, new State31());
            return true;

        /*
         * * : E30
         */
        case SU_MULT:
            automaton.transition(symbol, new State30());
            return true;

        /*
         * / : E32
         */
        case SU_DIV:
            automaton.transition(symbol, new State32());
            return true;


        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}