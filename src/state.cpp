#include <string>
#include <iostream>
#include "state.h"

using namespace std;

State::State(string name) {
    this->name = name;
}

void State::print() const {
    cout << "State : " << name << endl;
}

