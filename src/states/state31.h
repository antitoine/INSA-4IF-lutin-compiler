#ifndef LUTIN_COMPILER_STATE31_H
#define LUTIN_COMPILER_STATE31_H

class State31 : public State {

public:
    State31();
    ~State31();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE31_H