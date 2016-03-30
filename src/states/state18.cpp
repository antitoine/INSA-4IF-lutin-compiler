#include "state18.h"
#include "state19.h"
#include "state20.h"
#include "state33.h"
#include "../symbols/SymbolExpressionParenthesis.h"

State18::State18() : State("18") {
}

State18::~State18() {
}

bool State18::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

            /*
             * id : E19
             */

        case S_VARIABLE:
            automaton.addToCurrentExpression((SymbolExpression *) symbol);
            automaton.transition(symbol, new State19());
            return true;

            /*
             * val : E20
             */

        case S_NUMBER:
            automaton.addToCurrentExpression((SymbolExpression *) symbol);
            automaton.transition(symbol, new State20());
            return true;

            /*
             * ( : E18
             */

        case SYMBOL_UNIT_OPENING_PAR:
            automaton.addToCurrentExpression(new SymbolExpressionParenthesis());
            automaton.transition(symbol, new State18());
            return true;

            /*
             * E : E33
             */

        case SYMBOL_UNTERMINAL_E:
            automaton.transition(symbol, new State33());
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(),
                                               symbol->getNumCharDetection());

    }
}