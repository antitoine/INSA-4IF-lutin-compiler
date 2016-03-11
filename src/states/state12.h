#ifndef LUTIN_COMPILER_STATE12_H
#define LUTIN_COMPILER_STATE12_H

#include "state.h"

class State12 : public State {

public:
    State12();
    virtual ~State12();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

};

#endif //LUTIN_COMPILER_STATE12_H