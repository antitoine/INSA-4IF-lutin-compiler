#ifndef LUTIN_COMPILER_STATE20_H
#define LUTIN_COMPILER_STATE20_H

class State20 : public State {

public:
    State20();
    ~State20();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE20_H