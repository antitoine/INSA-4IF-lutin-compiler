#ifndef LUTIN_COMPILER_STATE14_H
#define LUTIN_COMPILER_STATE14_H

#include "state.h"

class State14 : public State {

public:
    State14();
    virtual ~State14();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

};

#endif //LUTIN_COMPILER_STATE14_H