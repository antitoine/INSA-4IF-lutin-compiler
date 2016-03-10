#ifndef LUTIN_COMPILER_STATE34_H
#define LUTIN_COMPILER_STATE34_H

class State34 : public State {

public:
    State34();
    ~State34();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE34_H