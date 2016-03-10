#ifndef LUTIN_COMPILER_STATE8_H
#define LUTIN_COMPILER_STATE8_H

#include "state.h"

class State8 : public State {

public:
    State8();
    virtual ~State8();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

};

#endif //LUTIN_COMPILER_STATE8_H