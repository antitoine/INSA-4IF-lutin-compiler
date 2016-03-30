#include "state5.h"
#include "state11.h"

State5::State5() : State(" 5") {
}

State5::~State5() {
}

bool State5::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

            /*
             * id : E11
             */

        case S_VARIABLE:
            automaton.addToCurrentExpression((SymbolExpression *) symbol);
            automaton.transition(symbol, new State11());
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(),
                                               symbol->getNumCharDetection());

    }
}