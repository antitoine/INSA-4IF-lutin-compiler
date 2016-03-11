#ifndef LUTIN_COMPILER_STATE4_H
#define LUTIN_COMPILER_STATE4_H

#include "state.h"

class State4 : public State {

public:
    State4();
    virtual ~State4();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

};

#endif //LUTIN_COMPILER_STATE4_H