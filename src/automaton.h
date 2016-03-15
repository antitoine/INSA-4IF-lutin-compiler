#ifndef LUTIN_COMPILER_AUTOMATE_H
#define LUTIN_COMPILER_AUTOMATE_H

#include <map>
#include <stack>
#include "states/state.h"

#include "StructVar.h"

class State;
class IActiveSymbol;
class SymbolDeclarationVar;
class SymbolDeclarationConst;
class SymbolVariable;
class SymbolNumber;

class Automaton {

private:
    std::map<Symbol*, StructVar> dicoVariables;
    IActiveSymbol * activeSymbol;
    std::stack<State*> stackStates;
    std::stack<Symbol*> stackSymbols;
    std::list<Symbol*> symbolsToExecute;

    SymbolDeclarationVar * currentSymbolDeclarationVar;
    SymbolDeclarationConst * currentSymbolDeclarationConst;

public :
    bool readFile(std::string filename);
    void transition(Symbol * symbol, State * newState);
    void reduction(int reductionSize, Symbol * unterminalSymbol);
    void accept();

    void setCurrentDeclarationVar(SymbolDeclarationVar * symbolDeclarationVar);
    void addVariableToCurrentDeclarationVar(SymbolVariable * variable);

    void setCurrentDeclarationConst(SymbolDeclarationConst * symbolDeclarationConst);
    void addConstantToCurrentDeclarationConst(SymbolVariable * variable);
    void addConstantValueToCurrentDeclarationConst(SymbolNumber * number);


private:
    void computeNewSymbol(Symbol * symbol);
    void init();
};


#endif //LUTIN_COMPILER_AUTOMATE_H
