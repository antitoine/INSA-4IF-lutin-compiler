#include "state23.h"
#include "../symbols/SymbolUnterminal.h"

State23::State23() : State("23") {
}

State23::~State23() {
}

bool State23::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R4 : D’ → var V ;
         * var    | R4
         * const  | R4
         * id     | R4
         * lire   | R4
         * ecrire | R4
         */

        case S_DECLARATION_VAR:
        case S_DECLARATION_CONST:
        case S_VARIABLE:
        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
            automaton.reduction(3, new SymbolUnterminal(SYMBOL_UNTERMINAL_D_PRIM));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}