#include "state42.h"
#include "../symbols/SymbolUnterminal.h"

State42::State42() : State("42") {
}

State42::~State42() {
}

bool State42::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {


        /*
         * R19 : E  → ( E )
         * ; | R19
         */
        case SU_SEMICOLON:
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

            /*
             * + | R19
             */
        case SU_PLUS:
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

            /*
             * - | R19
             */
        case SU_MINUS:
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

            /*
             * * | R19
             */
        case SU_MULT:
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

            /*
             * / | R19
             */
        case SU_DIV:
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;

            /*
            * ) | R19
            */
        case SU_ENDING_PAR:
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(UT_E));
            return true;


        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}