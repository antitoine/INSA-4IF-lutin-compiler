#ifndef LUTIN_COMPILER_STATE42_H
#define LUTIN_COMPILER_STATE42_H

#include "state.h"

class State42 : public State {

public:
    State42();
    ~State42();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE42_H