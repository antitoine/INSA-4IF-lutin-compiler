#ifndef LUTIN_COMPILER_STATE3_H
#define LUTIN_COMPILER_STATE3_H

class State3 : public State {

public:
    State3();
    ~State3();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE3_H