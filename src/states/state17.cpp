#include "state17.h"
#include "state28.h"
#include "state29.h"
#include "state30.h"
#include "state31.h"
#include "state32.h"

State17::State17() : State("17") {

}

State17::~State17() {

}

bool State17::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * ; : E28
         */
        case SU_SEMICOLON:
            automaton.transition(symbol, new State28());
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