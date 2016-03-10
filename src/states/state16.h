#ifndef LUTIN_COMPILER_STATE16_H
#define LUTIN_COMPILER_STATE16_H

class State16 : public State {

public:
    State16();
    ~State16();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE16_H