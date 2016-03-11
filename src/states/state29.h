#ifndef LUTIN_COMPILER_STATE29_H
#define LUTIN_COMPILER_STATE29_H

#include "state.h"

class State29 : public State {

public:
    State29();
    virtual ~State29();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE29_H