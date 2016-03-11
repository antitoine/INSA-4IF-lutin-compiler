#ifndef LUTIN_COMPILER_STATE33_H
#define LUTIN_COMPILER_STATE33_H

#include "state.h"

class State33 : public State {

public:
    State33();
    virtual ~State33();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

};

#endif //LUTIN_COMPILER_STATE33_H