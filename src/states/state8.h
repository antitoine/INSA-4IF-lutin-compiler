#ifndef LUTIN_COMPILER_STATE8_H
#define LUTIN_COMPILER_STATE8_H

class State8 : public State {

public:
    State8();
    ~State8();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE8_H