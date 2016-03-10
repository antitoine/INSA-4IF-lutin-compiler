#ifndef LUTIN_COMPILER_STATE17_H
#define LUTIN_COMPILER_STATE17_H

class State17 : public State {

public:
    State17();
    ~State17();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE17_H