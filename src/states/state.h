#ifndef LUTIN_COMPILER_STATE_H
#define LUTIN_COMPILER_STATE_H

#include <string>
#include <iostream>
#include "state.h"
#include "../Automaton.h"
#include "../symbols/Symbol.h"

class Automaton;

class State {

public:
    State(std::string name);
    void print() const;
    virtual ~State();
    virtual bool transition(Automaton & automaton, Symbol * symbol) = 0;

protected:
    std::string name;
};

#endif //LUTIN_COMPILER_STATE_H