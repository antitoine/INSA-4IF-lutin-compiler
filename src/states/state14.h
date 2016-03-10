#ifndef LUTIN_COMPILER_STATE14_H
#define LUTIN_COMPILER_STATE14_H

class State14 : public State {

public:
    State14();
    ~State14();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE14_H