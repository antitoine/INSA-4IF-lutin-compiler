#ifndef LUTIN_COMPILER_STATE4_H
#define LUTIN_COMPILER_STATE4_H

class State4 : public State {

public:
    State4();
    ~State4();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE4_H