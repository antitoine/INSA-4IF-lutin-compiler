#ifndef LUTIN_COMPILER_STATE25_H
#define LUTIN_COMPILER_STATE25_H

class State25 : public State {

public:
    State25();
    ~State25();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE25_H