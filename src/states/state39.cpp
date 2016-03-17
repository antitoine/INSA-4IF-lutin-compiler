#include "state39.h"
#include "../symbols/SymbolUnterminal.h"

State39::State39() : State("39") {
}

State39::~State39() {
}

bool State39::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R16 : E -> E * E
         * ; | R16
         * + | R16
         * - | R16
         * ) | R16
         * * | R16
         * / | R16
         */

        case SU_SEMICOLON:
        case SU_PLUS:
        case SU_MINUS:
        case SU_MULT:
        case SU_DIV:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

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