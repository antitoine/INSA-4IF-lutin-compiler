#ifndef LUTIN_COMPILER_AUTOMATE_H
#define LUTIN_COMPILER_AUTOMATE_H

#include <map>
#include <stack>
#include "states/state.h"

#include "StructVar.h"
#include "symbols/SymbolExpression.h"

using namespace std;

class State;
class IActiveSymbol;
class SymbolDeclarationVar;
class SymbolDeclarationConst;
class SymbolVariable;
class SymbolNumber;
class SymbolExpression;

class Automaton {

private:
    map<Symbol*, StructVar> dicoVariables;
    IActiveSymbol * activeSymbol;
    stack<State*> stackStates;
    stack<Symbol*> stackSymbols;
    list<Symbol*> symbolsToExecute;

    SymbolDeclarationVar * currentSymbolDeclarationVar;
    SymbolDeclarationConst * currentSymbolDeclarationConst;
    stack<SymbolExpression*> currentExpression;

    list<Symbol*> symbolsExpressionToAggregate;

public :
    bool readFile(string filename);
    void transition(Symbol * symbol, State * newState);
    void reduction(int reductionSize, Symbol * unterminalSymbol);
    void accept();

    void setCurrentDeclarationVar(SymbolDeclarationVar * symbolDeclarationVar);
    void addVariableToCurrentDeclarationVar(SymbolVariable * variable);

    void setCurrentDeclarationConst(SymbolDeclarationConst * symbolDeclarationConst);
    void addConstantToCurrentDeclarationConst(SymbolVariable * variable);
    void addConstantValueToCurrentDeclarationConst(SymbolNumber * number);

    void aggregateBinaryOperatorExpression();
    void aggregateParenthesisExpression();
    void addToCurrentExpression(SymbolExpression * expression);


private:
    void computeNewSymbol(Symbol * symbol);
    void init();
};


#endif //LUTIN_COMPILER_AUTOMATE_H
