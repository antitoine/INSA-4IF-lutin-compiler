#ifndef LUTIN_COMPILER_STATE21_H
#define LUTIN_COMPILER_STATE21_H

#include "state.h"

class State21 : public State {

public:
    State21();
    virtual ~State21();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE21_H