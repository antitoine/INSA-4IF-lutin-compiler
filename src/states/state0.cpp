#include "state0.h"
#include "../symbols/SymbolDeclaration.h"
#include "state1.h"

State0::State0()
    :State("")
{
}


State0::~State0()
{
}


bool State0::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * R3 : D -> Epsilon *
         * var   | R3
         * const | R3
         * id    | R3
         * lire  | R3
         * ecrire| R3
         */

        case S_DECLARATION_VAR:
        case S_DECLARATION_CONST:
        case S_VARIABLE:
        case S_INSTRUCTION_READ:
        case S_INSTRUCTION_WRITE:
            automaton.reduction(0, new State1());
            return true;

        /*
         * D     | E1
         */

        case S_DECLARATION:
            automaton.transition(symbol, new State1());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}