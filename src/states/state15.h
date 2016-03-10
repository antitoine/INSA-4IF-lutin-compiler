#ifndef LUTIN_COMPILER_STATE15_H
#define LUTIN_COMPILER_STATE15_H

class State15 : public State {

public:
    State15();
    ~State15();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE15_H