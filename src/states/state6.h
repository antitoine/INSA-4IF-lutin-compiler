#ifndef LUTIN_COMPILER_STATE6_H
#define LUTIN_COMPILER_STATE6_H

class State6 : public State {

public:
    State6();
    ~State6();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE6_H