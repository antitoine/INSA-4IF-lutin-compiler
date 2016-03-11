#ifndef LUTIN_COMPILER_STATE27_H
#define LUTIN_COMPILER_STATE27_H

class State27 : public State {

public:
    State27();
    virtual ~State27();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE27_H