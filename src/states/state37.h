#ifndef LUTIN_COMPILER_STATE37_H
#define LUTIN_COMPILER_STATE37_H

class State37 : public State {

public:
    State37();
    ~State37();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE37_H