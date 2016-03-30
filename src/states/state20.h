#ifndef LUTIN_COMPILER_STATE20_H
#define LUTIN_COMPILER_STATE20_H

#include "state.h"

class State20 : public State {

public:
    State20();

    virtual ~State20();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE20_H