#include "state28.h"
#include "../symbols/SymbolUnterminal.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State28::State28() : State("28") {
}

State28::~State28() {
}

bool State28::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R13 : I’ → ecrire E ;
         * id | R13
         * lire | R13
         * ecrire | R13
         * $ | R13
         */
        case S_VARIABLE:
        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
        case SYMBOL_UNIT_DOLLAR:
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_I_PRIM));
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(), symbol->getNumCharDetection());

    }
}