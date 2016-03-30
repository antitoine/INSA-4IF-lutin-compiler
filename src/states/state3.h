#ifndef LUTIN_COMPILER_STATE3_H
#define LUTIN_COMPILER_STATE3_H

#include "state.h"

class State3 : public State {

public:
    State3();

    virtual ~State3();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE3_H