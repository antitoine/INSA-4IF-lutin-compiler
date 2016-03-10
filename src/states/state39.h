#ifndef LUTIN_COMPILER_STATE39_H
#define LUTIN_COMPILER_STATE39_H

class State39 : public State {

public:
    State39();
    ~State39();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE39_H