#ifndef LUTIN_COMPILER_STATE21_H
#define LUTIN_COMPILER_STATE21_H

class State21 : public State {

public:
    State21();
    ~State21();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE21_H