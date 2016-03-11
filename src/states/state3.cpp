#include "state3.h"
#include "../symbols/SymbolUnterminal.h"

State3::State3() : State(" 3") {
}

State3::~State3() {
}

bool State3::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

        /*
         * R2 : D -> D D'
         * var   | R2
         * const | R2
         * id    | R2
         */
        case S_DECLARATION_VAR:
        case S_DECLARATION_CONST:
        case S_VARIABLE:
        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
            automaton.reduction(2, new SymbolUnterminal(UT_D));
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}