#ifndef LUTIN_COMPILER_STATE2_H
#define LUTIN_COMPILER_STATE2_H

#include "state.h"

class State2 : public State {

public:
    State2();

    virtual ~State2();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE2_H