#ifndef LUTIN_COMPILER_STATE10_H
#define LUTIN_COMPILER_STATE10_H

#include "state.h"

class State10 : public State {

public:
    State10();
    virtual ~State10();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE10_H