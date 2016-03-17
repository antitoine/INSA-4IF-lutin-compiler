#include "state38.h"
#include "state30.h"
#include "state32.h"
#include "../symbols/SymbolUnterminal.h"
#include "../symbols/SymbolExpressionBinaryMultiplication.h"
#include "../symbols/SymbolExpressionBinarySoustract.h"
#include "../symbols/SymbolExpressionBinaryAdd.h"
#include "../symbols/SymbolExpressionBinaryDivision.h"

State38::State38() : State("38") {
}

State38::~State38() {
}

bool State38::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R15 : E -> E + E
         * ; | R15
         * + | R15
         * - | R15
         * ) | R15
         */

        case SU_SEMICOLON:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

        case SU_PLUS:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

        case SU_MINUS:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

        case SU_ENDING_PAR:
            automaton.aggregateBinaryOperatorExpression();
            automaton.aggregateParenthesisExpression();
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

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}