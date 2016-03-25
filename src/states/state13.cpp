#include "state13.h"
#include "state23.h"
#include "state24.h"
#include "../exceptions/ErrorLexicalMissingSymbol.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"
#include "../symbols/SymbolUnit.h"

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