#ifndef LUTIN_COMPILER_STATE28_H
#define LUTIN_COMPILER_STATE28_H

#include "state.h"

class State28 : public State {

public:
    State28();
    virtual ~State28();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE28_H