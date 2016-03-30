#ifndef LUTIN_COMPILER_STATE32_H
#define LUTIN_COMPILER_STATE32_H

#include "state.h"

class State32 : public State {

public:
    State32();

    virtual ~State32();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE32_H