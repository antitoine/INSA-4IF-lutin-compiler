#include "state24.h"
#include "state35.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State24::State24() : State("24") {
}

State24::~State24() {
}

bool State24::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * id : E35
         */
        case S_VARIABLE:
            automaton.addVariableToCurrentDeclarationVar((SymbolVariable *) symbol);
            automaton.transition(symbol, new State35());
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(), symbol->getNumCharDetection());

    }
}