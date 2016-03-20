#include "state44.h"
#include "../symbols/SymbolUnterminal.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

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
        case SYMBOL_UNIT_SEMICOLON:
            automaton.reduction(5, new SymbolUnterminal(SYMBOL_UNTERMINAL_C));
            return true;

        /*
         * , | R8
         */
        case SYMBOL_UNIT_COMMA:
            automaton.reduction(5, new SymbolUnterminal(SYMBOL_UNTERMINAL_C));
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString());

    }
}