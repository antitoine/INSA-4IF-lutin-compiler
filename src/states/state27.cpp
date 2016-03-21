#include "state27.h"
#include "state37.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State27::State27() : State("27") {
}

State27::~State27() {
}

bool State27::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * val : E37
         */
        case S_NUMBER:
            automaton.addConstantValueToCurrentDeclarationConst((SymbolNumber *) symbol);
            automaton.transition(symbol, new State37());
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(), symbol->getNumCharDetection());

    }
}