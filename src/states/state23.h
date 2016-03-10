#ifndef LUTIN_COMPILER_STATE23_H
#define LUTIN_COMPILER_STATE23_H

class State23 : public State {

public:
    State23();
    ~State23();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE23_H