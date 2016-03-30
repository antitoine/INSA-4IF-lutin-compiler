#include "state38.h"
#include "state30.h"
#include "state32.h"
#include "../symbols/SymbolUnterminal.h"
#include "../symbols/SymbolExpressionBinaryMultiplication.h"
#include "../symbols/SymbolExpressionBinaryDivision.h"
#include "../symbols/SymbolUnit.h"

State38::State38() : State("38") {
}

State38::~State38() {
}

bool State38::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

            /*
             * R15 : E -> E + E
             * ; | R15
             * + | R15
             * - | R15
             * ) | R15
             */

        case SYMBOL_UNIT_SEMICOLON:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

        case SYMBOL_UNIT_PLUS:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

        case SYMBOL_UNIT_MINUS:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
            return true;

        case SYMBOL_UNIT_ENDING_PAR:
            automaton.aggregateBinaryOperatorExpression();
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_E));
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