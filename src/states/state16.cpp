#include "state16.h"
#include "state27.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State16::State16() : State("16") {
}

State16::~State16() {
}

bool State16::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * = : E27
         */
        case SYMBOL_UNIT_EQUAL:
            automaton.transition(symbol, new State27());
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString());

    }
}