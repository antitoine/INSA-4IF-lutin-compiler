#ifndef LUTIN_COMPILER_STATE11_H
#define LUTIN_COMPILER_STATE11_H

class State11 : public State {

public:
    State11();
    ~State11();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE11_H