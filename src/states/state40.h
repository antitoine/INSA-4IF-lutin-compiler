#ifndef LUTIN_COMPILER_STATE40_H
#define LUTIN_COMPILER_STATE40_H

class State40 : public State {

public:
    State40();
    virtual ~State40();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE40_H