#ifndef LUTIN_COMPILER_STATE34_H
#define LUTIN_COMPILER_STATE34_H

#include "state.h"

class State34 : public State {

public:
    State34();

    virtual ~State34();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE34_H