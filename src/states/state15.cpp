#include "state15.h"
#include "state25.h"
#include "state26.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"
#include "../symbols/SymbolUnit.h"

State15::State15() : State("15") {
}

State15::~State15() {
}

bool State15::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * ; : E25
         */
        case SYMBOL_UNIT_SEMICOLON:
            automaton.transition(symbol, new State25());
            return true;

        /*
        * , : E26
        */
        case SYMBOL_UNIT_COMMA:
            automaton.transition(symbol, new State26());
            return true;

        case S_VARIABLE:
            throw ErrorLexicalMissingSymbol(symbol->getNumLineDetection(), symbol->getNumCharDetection(), new SymbolUnit(SYMBOL_UNIT_COMMA));

        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
        case S_DECLARATION_CONST:
        case S_DECLARATION_VAR:
        case SYMBOL_UNIT_DOLLAR:
            throw ErrorLexicalMissingSymbol(symbol->getNumLineDetection(), symbol->getNumCharDetection(), new SymbolUnit(SYMBOL_UNIT_SEMICOLON));

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(), symbol->getNumCharDetection());

    }
}