#include "state22.h"
#include "state34.h"
#include "state29.h"
#include "state31.h"
#include "state30.h"
#include "state32.h"
#include "../symbols/SymbolExpressionBinaryAdd.h"
#include "../symbols/SymbolExpressionBinarySoustract.h"
#include "../symbols/SymbolExpressionBinaryMultiplication.h"
#include "../symbols/SymbolExpressionBinaryDivision.h"

State22::State22() : State("22") {
}

State22::~State22() {
}

bool State22::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {


        /*
         * ; : E34
         */
        case SYMBOL_UNIT_SEMICOLON:
            automaton.affectCurrentExpressionToCurrentInstruction();
            automaton.transition(symbol, new State34());
            return true;

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


        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}