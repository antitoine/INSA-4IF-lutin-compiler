#include <string>
#include <iostream>
#include "state.h"

using namespace std;

State::State(string name) : name(name) {
}

State::~State() {
}

void State::print() const {
    cout << "State : " << name << endl;
}

bool State::transition(Automaton & automaton, Symbol * symbol) {
    // TODO : make abstract
    return false;

}

