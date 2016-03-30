#ifndef LUTIN_COMPILER_STATE1_H
#define LUTIN_COMPILER_STATE1_H

#include "state.h"

class State1 : public State {

public:
    State1();

    virtual ~State1();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE1_H