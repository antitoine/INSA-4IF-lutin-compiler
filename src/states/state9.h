#ifndef LUTIN_COMPILER_STATE9_H
#define LUTIN_COMPILER_STATE9_H

class State9 : public State {

public:
    State9();
    ~State9();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE9_H