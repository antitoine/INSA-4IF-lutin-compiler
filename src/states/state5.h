#ifndef LUTIN_COMPILER_STATE5_H
#define LUTIN_COMPILER_STATE5_H

class State5 : public State {

public:
    State5();
    ~State5();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE5_H