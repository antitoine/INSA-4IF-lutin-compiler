#ifndef LUTIN_COMPILER_STATE33_H
#define LUTIN_COMPILER_STATE33_H

class State33 : public State {

public:
    State33();
    ~State33();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE33_H