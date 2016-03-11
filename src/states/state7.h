#ifndef LUTIN_COMPILER_STATE7_H
#define LUTIN_COMPILER_STATE7_H

#include "state.h"

class State7 : public State {

public:
    State7();
    ~State7();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE7_H