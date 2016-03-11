#include "state1.h"
#include "state7.h"
#include "state8.h"
#include "state9.h"

State1::State1() : State(" 1") {
}

State1::~State1() {
}


bool State1::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

        /*
         * var : E8
         */

        case S_DECLARATION_VAR:
            automaton.transition(symbol, new State8());
            return true;

        /*
         * const : E9
         */

        case S_DECLARATION_CONST:
            automaton.transition(symbol, new State9());
            return true;

        /*
         * id : E7
         * lire : E5
         * ecrire : E6
         * D' : E3
         * I : E2
         * I' : E4
         */

        case S_VARIABLE:
            automaton.transition(symbol, new State7());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}