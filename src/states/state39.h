#ifndef LUTIN_COMPILER_STATE39_H
#define LUTIN_COMPILER_STATE39_H

#include "state.h"

class State39 : public State {

public:
    State39();
    virtual ~State39();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE39_H