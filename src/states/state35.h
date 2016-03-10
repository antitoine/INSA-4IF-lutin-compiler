#ifndef LUTIN_COMPILER_STATE35_H
#define LUTIN_COMPILER_STATE35_H

class State35 : public State {

public:
    State35();
    ~State35();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE35_H