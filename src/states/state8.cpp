#include "state8.h"
#include "state13.h"
#include "state14.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State8::State8() : State(" 8") {
}

State8::~State8() {
}

bool State8::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * id : E14
         */

        case S_VARIABLE:
            automaton.addVariableToCurrentDeclarationVar((SymbolVariable *) symbol);
            automaton.transition(symbol, new State14());
            return true;

        /*
         * V : E13
         */

        case SYMBOL_UNTERMINAL_V:
            automaton.transition(symbol, new State13());
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString());

    }
}