#ifndef LUTIN_COMPILER_STATE38_H
#define LUTIN_COMPILER_STATE38_H

#include "state.h"

class State38 : public State {

public:
    State38();
    virtual ~State38();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE38_H