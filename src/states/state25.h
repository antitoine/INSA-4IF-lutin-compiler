#ifndef LUTIN_COMPILER_STATE25_H
#define LUTIN_COMPILER_STATE25_H

#include "state.h"

class State25 : public State {

public:
    State25();
    virtual ~State25();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

};

#endif //LUTIN_COMPILER_STATE25_H