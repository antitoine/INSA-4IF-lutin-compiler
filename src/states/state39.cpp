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

        case SYMBOL_UNIT_SEMICOLON:
        case SYMBOL_UNIT_PLUS:
        case SYMBOL_UNIT_MINUS:
        case SYMBOL_UNIT_MULT:
        case SYMBOL_UNIT_DIV:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

        case SYMBOL_UNIT_ENDING_PAR:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}