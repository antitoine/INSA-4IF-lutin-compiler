#ifndef LUTIN_COMPILER_STATE0_H
#define LUTIN_COMPILER_STATE0_H

class State0 : public State {

public:
    State0();
    ~State0();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE0_H