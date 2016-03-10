#ifndef LUTIN_COMPILER_STATE32_H
#define LUTIN_COMPILER_STATE32_H

class State32 : public State {

public:
    State32();
    ~State32();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE32_H