#ifndef LUTIN_COMPILER_STATE35_H
#define LUTIN_COMPILER_STATE35_H

#include "state.h"

class State35 : public State {

public:
    State35();
    virtual ~State35();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

};

#endif //LUTIN_COMPILER_STATE35_H