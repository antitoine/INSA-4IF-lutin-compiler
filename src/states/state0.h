#ifndef LUTIN_COMPILER_STATE0_H
#define LUTIN_COMPILER_STATE0_H

#include "state.h"

class State0 : public State {

public:
    State0();

    virtual ~State0();

    virtual bool transition(Automaton &automaton, Symbol *symbol);
};

#endif //LUTIN_COMPILER_STATE0_H