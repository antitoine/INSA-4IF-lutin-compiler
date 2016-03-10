#ifndef LUTIN_COMPILER_STATE1_H
#define LUTIN_COMPILER_STATE1_H

class State1 : public State {

public:
    State1();
    ~State1();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE1_H