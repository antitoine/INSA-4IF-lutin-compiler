#include "state1.h"
#include "state2.h"
#include "state3.h"
#include "state4.h"
#include "state5.h"
#include "state6.h"
#include "state7.h"
#include "state8.h"
#include "state9.h"
#include "../symbols/SymbolDeclarationConst.h"
#include "../symbols/SymbolInstructionAffect.h"
#include "../exceptions/ErrorLexicalUnexpectedSymbol.h"

State1::State1() : State(" 1") {
}

State1::~State1() {
}

bool State1::transition(Automaton &automaton, Symbol *symbol) {
    switch (symbol->getId()) {

        /*
         * var : E8
         */

        case S_DECLARATION_VAR:
            automaton.setCurrentDeclarationVar((SymbolDeclarationVar *) symbol);
            automaton.transition(symbol, new State8());
            return true;

        /*
         * const : E9
         */

        case S_DECLARATION_CONST:
            automaton.setCurrentDeclarationConst((SymbolDeclarationConst *) symbol);
            automaton.transition(symbol, new State9());
            return true;

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
            automaton.setCurrentInstruction((SymbolInstruction *) symbol);
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
         * D' : E3
         */

        case SYMBOL_UNTERMINAL_D_PRIM:
            automaton.transition(symbol, new State3());
            return true;

        /*
         * I : E2
         */

        case SYMBOL_UNTERMINAL_I:
            automaton.transition(symbol, new State2());
            return true;

        /*
         * I' : E4
         */

        case SYMBOL_UNTERMINAL_I_PRIM:
            automaton.transition(symbol, new State4());
            return true;

        default:
            throw ErrorLexicalUnexpectedSymbol(symbol->toString(), symbol->getNumLineDetection(), symbol->getNumCharDetection(), true);

    }
}