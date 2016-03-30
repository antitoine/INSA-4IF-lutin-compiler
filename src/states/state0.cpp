#include "state0.h"
#include "state1.h"
#include "../symbols/SymbolUnterminal.h"

State0::State0() : State(" 0") {
}

State0::~State0() {
}

bool State0::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

            /*
             * R3 : D -> Epsilon
             * var    | R3
             * const  | R3
             * id     | R3
             * lire   | R3
             * ecrire | R3
             */

        case S_DECLARATION_VAR:
        case S_DECLARATION_CONST:
        case S_VARIABLE:
        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
            automaton.reduction(0, new SymbolUnterminal(SYMBOL_UNTERMINAL_D));
            return true;

            /*
             * D : E1
             */

        case SYMBOL_UNTERMINAL_D:
            automaton.transition(symbol, new State1());
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(),
                                               symbol->getNumCharDetection());
    }
}