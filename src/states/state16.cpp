#include "state16.h"
#include "state27.h"
#include "../symbols/SymbolUnit.h"

State16::State16() : State("16") {
}

State16::~State16() {
}

bool State16::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

            /*
             * = : E27
             */

        case SYMBOL_UNIT_EQUAL:
            automaton.transition(symbol, new State27());
            return true;

        case SYMBOL_UNIT_AFFECT:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(),
                                               symbol->getNumCharDetection(), new SymbolUnit(SYMBOL_UNIT_EQUAL));

        default:
            throw ErrorLexicalMissingSymbol(symbol->getNumLineDetection(), symbol->getNumCharDetection(),
                                            new SymbolUnit(SYMBOL_UNIT_EQUAL));

    }
}