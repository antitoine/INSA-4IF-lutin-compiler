#ifndef LUTIN_COMPILER_STATE30_H
#define LUTIN_COMPILER_STATE30_H

class State30 : public State {

public:
    State30();
    virtual ~State30();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE30_H