#ifndef LUTIN_COMPILER_STATE_H
#define LUTIN_COMPILER_STATE_H

#include <string>
#include <iostream>
#include "symbol.h"
#include "automaton.h"

using namespace std;

class State {

public:
    State(string name);
    void print() const;
    virtual ~State();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

protected:
    string name;
};

#endif //LUTIN_COMPILER_STATE_H