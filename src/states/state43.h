#ifndef LUTIN_COMPILER_STATE43_H
#define LUTIN_COMPILER_STATE43_H

#include "state.h"

class State43 : public State {

public:
    State43();
    virtual ~State43();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE43_H