#ifndef LUTIN_COMPILER_STATE24_H
#define LUTIN_COMPILER_STATE24_H

class State24 : public State {

public:
    State24();
    ~State24();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE24_H