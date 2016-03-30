#include "state35.h"
#include "../symbols/SymbolUnterminal.h"
#include "../symbols/SymbolUnit.h"

State35::State35() : State("35") {
}

State35::~State35() {
}

bool State35::transition(Automaton &automaton, Symbol *symbol) {
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

        case S_VARIABLE:
            throw ErrorLexicalMissingSymbol(symbol->getNumLineDetection(), symbol->getNumCharDetection(),
                                            new SymbolUnit(SYMBOL_UNIT_COMMA));

        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
        case S_DECLARATION_CONST:
        case S_DECLARATION_VAR:
        case SYMBOL_UNIT_DOLLAR:
            throw ErrorLexicalMissingSymbol(symbol->getNumLineDetection(), symbol->getNumCharDetection(),
                                            new SymbolUnit(SYMBOL_UNIT_SEMICOLON));

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(),
                                               symbol->getNumCharDetection());

    }
}