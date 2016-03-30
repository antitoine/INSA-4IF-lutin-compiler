#ifndef LUTIN_COMPILER_STATE23_H
#define LUTIN_COMPILER_STATE23_H

#include "state.h"

class State23 : public State {

public:
    State23();

    virtual ~State23();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE23_H