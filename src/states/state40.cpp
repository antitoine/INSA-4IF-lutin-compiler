#include "state40.h"
#include "../symbols/SymbolUnterminal.h"
#include "state30.h"
#include "state32.h"
#include "../symbols/SymbolExpressionBinaryMultiplication.h"
#include "../symbols/SymbolExpressionBinaryDivision.h"

State40::State40() : State("40") {
}

State40::~State40() {
}

bool State40::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {


        /*
         * R17 : E  → E - E
         * ; | R17
         */
        case SU_SEMICOLON:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

        /*
         * + | R17
         */
        case SU_PLUS:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

        /*
         * - | R17
         */
        case SU_MINUS:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

        /*
         * * : E30
         */
        case SU_MULT:
            automaton.addToCurrentExpression(new SymbolExpressionBinaryMultiplication());
            automaton.transition(symbol, new State30());
            return true;

        /*
         * / : E32
         */
        case SU_DIV:
            automaton.addToCurrentExpression(new SymbolExpressionBinaryDivision());
            automaton.transition(symbol, new State32());
            return true;

        /*
        * ) | R17
        */
        case SU_ENDING_PAR:
            automaton.aggregateBinaryOperatorExpression();
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;


        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}