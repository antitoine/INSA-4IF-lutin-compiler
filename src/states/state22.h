#ifndef LUTIN_COMPILER_STATE22_H
#define LUTIN_COMPILER_STATE22_H

class State22 : public State {

public:
    State22();
    virtual ~State22();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE22_H