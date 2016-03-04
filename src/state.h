#ifndef STATE_H
#define STATE_H

#include <string>
#include <iostream>

using namespace std;

class State {

public:
    State(string name);
    void print() const;
    virtual ~State();
    virtual bool transition(Automaton & automaton, Symbol * symbol);

protected:
    string name;
};

#endif //STATE_H