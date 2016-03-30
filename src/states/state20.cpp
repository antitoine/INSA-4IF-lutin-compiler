#include "state20.h"
#include "../symbols/SymbolUnterminal.h"
#include "../symbols/SymbolUnit.h"

State20::State20() : State("20") {
}

State20::~State20() {
}

bool State20::transition(Automaton &automaton, Symbol *symbol) {
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

        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
        case S_DECLARATION_CONST:
        case S_DECLARATION_VAR:
        case S_VARIABLE:
        case SYMBOL_UNIT_DOLLAR:
            throw ErrorLexicalMissingSymbol(symbol->getNumLineDetection(), symbol->getNumCharDetection(),
                                            new SymbolUnit(SYMBOL_UNIT_SEMICOLON));

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(),
                                               symbol->getNumCharDetection());

    }
}