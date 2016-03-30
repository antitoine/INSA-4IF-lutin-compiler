#include "state42.h"
#include "../symbols/SymbolUnterminal.h"
#include "../symbols/SymbolUnit.h"

State42::State42() : State("42") {
}

State42::~State42() {
}

bool State42::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {


            /*
             * R19 : E  → ( E )
             * ; | R19
             */

        case SYMBOL_UNIT_SEMICOLON:
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

            /*
             * + | R19
             */

        case SYMBOL_UNIT_PLUS:
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

            /*
             * - | R19
             */

        case SYMBOL_UNIT_MINUS:
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

            /*
             * * | R19
             */

        case SYMBOL_UNIT_MULT:
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

            /*
             * / | R19
             */

        case SYMBOL_UNIT_DIV:
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

           /*
            * ) | R19
            */

        case SYMBOL_UNIT_ENDING_PAR:
            automaton.aggregateParenthesisExpression();
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

        case S_VARIABLE:
        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
        case S_DECLARATION_CONST:
        case S_DECLARATION_VAR:
        case SYMBOL_UNIT_DOLLAR:
            throw ErrorLexicalMissingSymbol(symbol->getNumLineDetection(), symbol->getNumCharDetection(),
                                            new SymbolUnit(SYMBOL_UNIT_SEMICOLON));


        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(),
                                               symbol->getNumCharDetection());

    }
}