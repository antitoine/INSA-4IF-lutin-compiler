#ifndef LUTIN_COMPILER_STATE27_H
#define LUTIN_COMPILER_STATE27_H

#include "state.h"

class State27 : public State {

public:
    State27();
    ~State27();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE27_H