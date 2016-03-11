#ifndef LUTIN_COMPILER_STATE19_H
#define LUTIN_COMPILER_STATE19_H

#include "state.h"

class State19 : public State {

public:
    State19();
    virtual ~State19();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE19_H