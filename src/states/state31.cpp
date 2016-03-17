#include "state31.h"
#include "state18.h"
#include "state19.h"
#include "state20.h"
#include "state40.h"

State31::State31() : State("31") {
}

State31::~State31() {
}

bool State31::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

        /*
         * id : E19
         */

        case S_VARIABLE:
            automaton.addToCurrentExpression((SymbolExpression *) symbol);
            automaton.transition(symbol, new State19());
            return true;

        /*
         * val : E20
         */

        case S_NUMBER:
            automaton.addToCurrentExpression((SymbolExpression *) symbol);
            automaton.transition(symbol, new State20());
            return true;

        /*
         * ( : E18
         */

        case SU_OPENNING_PAR:
            automaton.transition(symbol, new State18());
            return true;

        /*
         * E : E40
         */

        case UT_E:
            automaton.transition(symbol, new State40());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}