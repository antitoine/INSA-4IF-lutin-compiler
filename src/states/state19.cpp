#include "state19.h"
#include "../symbols/SymbolUnterminal.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"
#include "../symbols/SymbolUnit.h"

State19::State19() : State("19") {
}

State19::~State19() {
}

bool State19::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R20 : E  → id
         * ; | R20
         * + | R20
         * - | R20
         * * | R20
         * / | R20
         * ) | R20
         */
        case SYMBOL_UNIT_SEMICOLON:
        case SYMBOL_UNIT_PLUS:
        case SYMBOL_UNIT_MINUS:
        case SYMBOL_UNIT_MULT:
        case SYMBOL_UNIT_DIV:
        case SYMBOL_UNIT_ENDING_PAR:
            automaton.reduction(1, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
        case S_DECLARATION_CONST:
        case S_DECLARATION_VAR:
        case S_VARIABLE:
            throw ErrorLexicalMissingSymbol(symbol->getNumLineDetection(), symbol->getNumCharDetection(), new SymbolUnit(SYMBOL_UNIT_SEMICOLON));

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(), symbol->getNumCharDetection());

    }
}