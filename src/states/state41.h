#ifndef LUTIN_COMPILER_STATE41_H
#define LUTIN_COMPILER_STATE41_H

class State41 : public State {

public:
    State41();
    ~State41();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE41_H