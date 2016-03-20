#include "state26.h"
#include "state36.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State26::State26() : State("26") {
}

State26::~State26() {
}

bool State26::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * id : E36
         */
        case S_VARIABLE:
            automaton.addConstantToCurrentDeclarationConst((SymbolVariable *) symbol);
            automaton.transition(symbol, new State36());
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString());

    }
}