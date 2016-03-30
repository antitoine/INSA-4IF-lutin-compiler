#ifndef LUTIN_COMPILER_STATE_H
#define LUTIN_COMPILER_STATE_H

#include <string>
#include <iostream>
#include "state.h"
#include "../Automaton.h"
#include "../symbols/Symbol.h"

using namespace std;

class Automaton;

/**
 * Abstract class representing a state of the automaton.
 */
class State {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    /**
     * Constructor.
     * @param name The name of the state.
     */
    State(string name);

    /**
     * Destructor.
     */
    virtual ~State();

    /**
     * Print on std::cout the name of the state.
     */
    void print() const;

    /**
     * Abstract method: Make the transition on the automation passed by parameter, for the symbol read and also passed
     * by parameter.
     * @param automaton The automaton to use to make the transition.
     * @param symbol The symbol previously read and detected, to compute by the state.
     */
    virtual bool transition(Automaton &automaton, Symbol *symbol) = 0;

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /** The state's name. */
    string name;
};

#endif //LUTIN_COMPILER_STATE_H