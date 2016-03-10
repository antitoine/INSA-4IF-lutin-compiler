#ifndef LUTIN_COMPILER_STATE18_H
#define LUTIN_COMPILER_STATE18_H

class State18 : public State {

public:
    State18();
    ~State18();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE18_H