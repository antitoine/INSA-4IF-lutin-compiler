#ifndef LUTIN_COMPILER_STATE44_H
#define LUTIN_COMPILER_STATE44_H

#include "state.h"

class State44 : public State {

public:
    State44();

    virtual ~State44();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE44_H