#ifndef LUTIN_COMPILER_STATE22_H
#define LUTIN_COMPILER_STATE22_H

#include "state.h"

class State22 : public State {

public:
    State22();

    virtual ~State22();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE22_H