#ifndef LUTIN_COMPILER_STATE43_H
#define LUTIN_COMPILER_STATE43_H

class State43 : public State {

public:
    State43();
    ~State43();
    bool transition(Automaton automaton, Symbol symbol);

};

#endif //LUTIN_COMPILER_STATE43_H