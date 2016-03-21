#include "state13.h"
#include "state23.h"
#include "state24.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State13::State13() : State("13") {
}

State13::~State13() {
}


bool State13::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * ; : E23
         */
        case SYMBOL_UNIT_SEMICOLON:
            automaton.transition(symbol, new State23());
            return true;

        /*
        * , : E24
        */
        case SYMBOL_UNIT_COMMA:
            automaton.transition(symbol, new State24());
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(), symbol->getNumCharDetection());

    }
}