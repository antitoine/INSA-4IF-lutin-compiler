#ifndef LUTIN_COMPILER_STATE36_H
#define LUTIN_COMPILER_STATE36_H

#include "state.h"

class State36 : public State {

public:
    State36();

    virtual ~State36();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE36_H