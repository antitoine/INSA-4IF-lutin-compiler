#ifndef LUTIN_COMPILER_STATE28_H
#define LUTIN_COMPILER_STATE28_H

class State28 : public State {

public:
    State28();
    ~State28();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE28_H