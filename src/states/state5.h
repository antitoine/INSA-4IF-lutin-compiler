#ifndef LUTIN_COMPILER_STATE5_H
#define LUTIN_COMPILER_STATE5_H

#include "state.h"

class State5 : public State {

public:
    State5();
    virtual ~State5();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

};

#endif //LUTIN_COMPILER_STATE5_H