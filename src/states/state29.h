#ifndef LUTIN_COMPILER_STATE29_H
#define LUTIN_COMPILER_STATE29_H

class State29 : public State {

public:
    State29();
    ~State29();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE29_H