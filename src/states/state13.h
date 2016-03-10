#ifndef LUTIN_COMPILER_STATE13_H
#define LUTIN_COMPILER_STATE13_H

class State13 : public State {

public:
    State13();
    ~State13();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE13_H