#include "state37.h"
#include "../symbols/SymbolUnterminal.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State37::State37() : State("37") {
}

State37::~State37() {
}

bool State37::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R9 : C -> id = val
         * ; | R9
         * , | R9
         */

        case SYMBOL_UNIT_SEMICOLON:
        case SYMBOL_UNIT_COMMA:
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_C));
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(), symbol->getNumCharDetection(), true);

    }
}