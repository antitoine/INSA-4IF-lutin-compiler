#include "state33.h"
#include "state29.h"
#include "state30.h"
#include "state31.h"
#include "state32.h"
#include "state42.h"
#include "../symbols/SymbolExpressionBinarySoustract.h"
#include "../symbols/SymbolExpressionBinaryAdd.h"
#include "../symbols/SymbolExpressionBinaryMultiplication.h"
#include "../symbols/SymbolExpressionBinaryDivision.h"

State33::State33() : State("33") {
}

State33::~State33() {
}

bool State33::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * + : E29
         */
        case SYMBOL_UNIT_PLUS:
            automaton.addToCurrentExpression(new SymbolExpressionBinaryAdd());
            automaton.transition(symbol, new State29());
            return true;

        /*
         * - : E31
         */
        case SYMBOL_UNIT_MINUS:
            automaton.addToCurrentExpression(new SymbolExpressionBinarySoustract());
            automaton.transition(symbol, new State31());
            return true;

        /*
         * * : E30
         */
        case SYMBOL_UNIT_MULT:
            automaton.addToCurrentExpression(new SymbolExpressionBinaryMultiplication());
            automaton.transition(symbol, new State30());
            return true;

        /*
         * / : E32
         */
        case SYMBOL_UNIT_DIV:
            automaton.addToCurrentExpression(new SymbolExpressionBinaryDivision());
            automaton.transition(symbol, new State32());
            return true;

        /*
         * ) : E42
         */
        case SYMBOL_UNIT_ENDING_PAR:
            automaton.transition(symbol, new State42());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}