#include "state35.h"
#include "../symbols/SymbolUnterminal.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State35::State35() : State("35") {
}

State35::~State35() {
}

bool State35::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R7 : V -> id
         * ; | R7
         * , | R7
         */

        case SYMBOL_UNIT_SEMICOLON:
        case SYMBOL_UNIT_COMMA:
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_V));
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString());

    }
}