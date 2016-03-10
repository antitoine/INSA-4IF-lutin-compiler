#ifndef LUTIN_COMPILER_STATE19_H
#define LUTIN_COMPILER_STATE19_H

class State19 : public State {

public:
    State19();
    ~State19();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE19_H