#ifndef LUTIN_COMPILER_AUTOMATE_H
#define LUTIN_COMPILER_AUTOMATE_H

#include <map>
#include <stack>

#include "state.h"

using namespace std;

class State;
class IActiveSymbol;

typedef struct structVar {
    // What define a symbol : what it contains and if it's constant
    float value;
    bool constant;
} StructVar;

class Automaton {

private:
    map<Symbol*, StructVar> dicoVariables;
    IActiveSymbol activeSymbol();
    stack<State> stackStates;

public :
    void readFile(string filename);
};


#endif //LUTIN_COMPILER_AUTOMATE_H
