#include "state9.h"
#include "state15.h"
#include "state16.h"

State9::State9() : State(" 9") {
}

State9::~State9() {
}

bool State9::transition(Automaton & automaton, Symbol * symbol) {
    switch (symbol->getId()) {

        /*
         * id : E16
         */

        case S_VARIABLE:
            automaton.addConstantToCurrentDeclarationConst((SymbolVariable *) symbol);
            automaton.transition(symbol, new State16());
            return true;

        /*
         * C : E15
         */

        case SYMBOL_UNTERMINAL_C:
            automaton.transition(symbol, new State15());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}