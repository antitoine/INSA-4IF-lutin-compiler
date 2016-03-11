#ifndef LUTIN_COMPILER_STATE9_H
#define LUTIN_COMPILER_STATE9_H

#include "state.h"

class State9 : public State {

public:
    State9();
    virtual ~State9();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

};

#endif //LUTIN_COMPILER_STATE9_H