#include "state2.h"
#include "state5.h"
#include "state6.h"
#include "state7.h"
#include "state10.h"
#include "../symbols/SymbolInstructionAffect.h"

State2::State2() : State(" 2") {
}

State2::~State2() {
}

bool State2::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

        /*
         * id : E7
         */

        case S_VARIABLE:
            automaton.setCurrentInstruction(new SymbolInstructionAffect((SymbolVariable *) symbol));
            automaton.transition(symbol, new State7());
            return true;

        /*
         * lire : E5
         */

        case S_INSTRUCTION_READ:
            automaton.transition(symbol, new State5());
            return true;

        /*
         * ecrire : E6
         */

        case S_INSTRUCTION_WRITE:
            automaton.setCurrentInstruction((SymbolInstruction *) symbol);
            automaton.transition(symbol, new State6());
            return true;

        /*
         * $ : Accepted
         */

        case SU_DOLLAR:
            automaton.accept();
            return true;

        /*
         * I' : E10
         */

        case UT_I:
            automaton.transition(symbol, new State10());
            return true;

        default:
            // TODO : handle exceptions with warning message
            return false;
    }
}