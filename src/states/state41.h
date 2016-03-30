#ifndef LUTIN_COMPILER_STATE41_H
#define LUTIN_COMPILER_STATE41_H

#include "state.h"

class State41 : public State {

public:
    State41();

    virtual ~State41();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE41_H