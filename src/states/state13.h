#ifndef LUTIN_COMPILER_STATE13_H
#define LUTIN_COMPILER_STATE13_H

#include "state.h"

class State13 : public State {

public:
    State13();
    virtual ~State13();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

};

#endif //LUTIN_COMPILER_STATE13_H