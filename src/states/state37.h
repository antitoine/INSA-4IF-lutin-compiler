#ifndef LUTIN_COMPILER_STATE37_H
#define LUTIN_COMPILER_STATE37_H

#include "state.h"

class State37 : public State {

public:
    State37();
    virtual ~State37();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

};

#endif //LUTIN_COMPILER_STATE37_H