#ifndef LUTIN_COMPILER_AUTOMATE_H
#define LUTIN_COMPILER_AUTOMATE_H

#include <map>
#include <stack>
#include <list>
#include "states/state.h"

#include "StructVar.h"

using namespace std;

class State;
class IActiveSymbol;
class Symbol;
class SymbolDeclarationVar;
class SymbolDeclarationConst;
class SymbolVariable;
class SymbolNumber;
class SymbolExpression;
class SymbolInstruction;

class Automaton {

private:
    map<string, StructVar*>dicoVariables;
    stack<State*> stackStates;
    stack<Symbol*> stackSymbols;
    list<Symbol*> symbolsToExecute;

    SymbolDeclarationVar * currentSymbolDeclarationVar;
    SymbolDeclarationConst * currentSymbolDeclarationConst;

    list<SymbolExpression*> currentExpression;
    SymbolInstruction * currentInstruction;

    int currentLineError;
    int currentCharPosError;

public :
    int readFile(string filename);
    void transition(Symbol * symbol, State * newState);
    void reduction(int reductionSize, Symbol * unterminalSymbol);
    void accept();

    void initDicoVariables();
    int execute();
    void checkProgram();

    void setCurrentDeclarationVar(SymbolDeclarationVar * symbolDeclarationVar);
    void addVariableToCurrentDeclarationVar(SymbolVariable * variable);

    void setCurrentDeclarationConst(SymbolDeclarationConst * symbolDeclarationConst);
    void addConstantToCurrentDeclarationConst(SymbolVariable * variable);
    void addConstantValueToCurrentDeclarationConst(SymbolNumber * number);

    void setCurrentInstruction(SymbolInstruction * instruction);
    void affectCurrentExpressionToCurrentInstruction();

    void aggregateBinaryOperatorExpression();
    void aggregateParenthesisExpression();
    void addToCurrentExpression(SymbolExpression * expression);

    string programmeToString() const;

    virtual ~Automaton();


private:
    void computeNewSymbol(Symbol * symbol);
    void init();

    void checkProgramVariablesUsed();
};


#endif //LUTIN_COMPILER_AUTOMATE_H
