#include "state20.h"
#include "../symbols/SymbolUnterminal.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State20::State20() : State("20") {
}

State20::~State20() {
}

bool State20::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R21 : E  → val
         * ; | R21
         * + | R21
         * - | R21
         * * | R21
         * / | R21
         * ) | R21
         */
        case SYMBOL_UNIT_SEMICOLON:
        case SYMBOL_UNIT_PLUS:
        case SYMBOL_UNIT_MINUS:
        case SYMBOL_UNIT_MULT:
        case SYMBOL_UNIT_DIV:
        case SYMBOL_UNIT_ENDING_PAR:
            automaton.reduction(1, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(), symbol->getNumCharDetection(), true);

    }
}