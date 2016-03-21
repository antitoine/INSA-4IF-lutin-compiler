#include "state4.h"
#include "../symbols/SymbolUnterminal.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State4::State4() : State(" 4") {
}

State4::~State4() {
}

bool State4::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

        /*
         * R11 : I -> I'
         * id     | R11
         * lire   | R11
         * ecrire | R11
         * $      | R11
         */
        case S_VARIABLE:
        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
        case SYMBOL_UNIT_DOLLAR:
            automaton.reduction(1, new SymbolUnterminal(SYMBOL_UNTERMINAL_I));
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(), symbol->getNumCharDetection());

    }
}