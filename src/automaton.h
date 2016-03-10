#ifndef LUTIN_COMPILER_AUTOMATE_H
#define LUTIN_COMPILER_AUTOMATE_H

#include <map>
#include <stack>

#include "state.h"

class State;
class IActiveSymbol;

typedef struct structVar {
    // What define a symbol : what it contains and if it's constant
    float value;
    bool constant;
} StructVar;

class Automaton {

private:
    std::map<Symbol*, StructVar> dicoVariables;
    IActiveSymbol * activeSymbol;
    std::stack<State*> stackStates;
    std::stack<Symbol*> stackSymbols;

public :
    bool readFile(std::string filename);

private:
    void computeNewSymbol(Symbol * symbol);
};


#endif //LUTIN_COMPILER_AUTOMATE_H
