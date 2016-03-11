#ifndef LUTIN_COMPILER_STATE26_H
#define LUTIN_COMPILER_STATE26_H

#include "state.h"

class State26 : public State {

public:
    State26();
    virtual ~State26();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

};

#endif //LUTIN_COMPILER_STATE26_H