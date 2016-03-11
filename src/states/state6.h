#ifndef LUTIN_COMPILER_STATE6_H
#define LUTIN_COMPILER_STATE6_H

#include "state.h"

class State6 : public State {

public:
    State6();
    virtual ~State6();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE6_H