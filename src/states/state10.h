#ifndef LUTIN_COMPILER_STATE10_H
#define LUTIN_COMPILER_STATE10_H

class State10 : public State {

public:
    State10();
    ~State10();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE10_H