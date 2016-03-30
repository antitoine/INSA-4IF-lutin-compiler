#include "state6.h"
#include "state17.h"
#include "state18.h"
#include "state19.h"
#include "state20.h"
#include "../symbols/SymbolExpressionParenthesis.h"

State6::State6() : State(" 6") {
}

State6::~State6() {
}

bool State6::transition(Automaton &automaton, Symbol *symbol) {
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
             * E : E17
             */
        case SYMBOL_UNTERMINAL_E:
            automaton.transition(symbol, new State17());
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(),
                                               symbol->getNumCharDetection());

    }
}