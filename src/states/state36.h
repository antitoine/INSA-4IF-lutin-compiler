#ifndef LUTIN_COMPILER_STATE36_H
#define LUTIN_COMPILER_STATE36_H

class State36 : public State {

public:
    State36();
    ~State36();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE36_H