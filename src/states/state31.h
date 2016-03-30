#ifndef LUTIN_COMPILER_STATE31_H
#define LUTIN_COMPILER_STATE31_H

#include "state.h"

class State31 : public State {

public:
    State31();

    virtual ~State31();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE31_H