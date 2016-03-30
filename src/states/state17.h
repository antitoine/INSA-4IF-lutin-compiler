#ifndef LUTIN_COMPILER_STATE17_H
#define LUTIN_COMPILER_STATE17_H

#include "state.h"

class State17 : public State {

public:
    State17();

    virtual ~State17();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE17_H