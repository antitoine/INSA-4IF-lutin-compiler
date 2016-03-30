#ifndef LUTIN_COMPILER_STATE16_H
#define LUTIN_COMPILER_STATE16_H

#include "state.h"

class State16 : public State {

public:
    State16();

    virtual ~State16();

    virtual bool transition(Automaton &automaton, Symbol *symbol);

};

#endif //LUTIN_COMPILER_STATE16_H