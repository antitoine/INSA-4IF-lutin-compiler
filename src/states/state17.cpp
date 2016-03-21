#include "state17.h"
#include "state28.h"
#include "state29.h"
#include "state30.h"
#include "state31.h"
#include "state32.h"
#include "../symbols/SymbolExpressionBinaryAdd.h"
#include "../symbols/SymbolExpressionBinaryMultiplication.h"
#include "../symbols/SymbolExpressionBinarySubstract.h"
#include "../symbols/SymbolExpressionBinaryDivision.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State17::State17() : State("17") {
}

State17::~State17() {
}

bool State17::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * ; : E28
         */
        case SYMBOL_UNIT_SEMICOLON:
            automaton.affectCurrentExpressionToCurrentInstruction();
            automaton.transition(symbol, new State28());
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
            automaton.addToCurrentExpression(new SymbolExpressionBinarySubstract());
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
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(), symbol->getNumCharDetection());

    }
}