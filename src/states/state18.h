#ifndef LUTIN_COMPILER_STATE18_H
#define LUTIN_COMPILER_STATE18_H

#include "state.h"

class State18 : public State {

public:
    State18();

    virtual ~State18();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE18_H