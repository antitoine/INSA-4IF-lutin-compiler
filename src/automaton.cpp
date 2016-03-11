#include <ostream>
#include <iostream>
#include <fstream>
#include <list>
#include "automaton.h"
#include "Lexer.h"
#include "states/state0.h"

void Automaton::init() {
    // TODO
    stackStates.push(new State0());
}

bool Automaton::readFile(std::string filename) {

    init();

    std::string line;
    std::ifstream file(filename);
    Symbol * symbol;

    if (!file.is_open())
    {
        std::cerr << "Error: unable to open the file " << filename << std::endl;
        return false;
    }

    std::cout << "File " << filename << " opened." << std::endl;

    // TODO : line too long
    while (std::getline(file, line))
    {
        std::string stringToCompute(line);

        while (!stringToCompute.empty())
        {
            std::cout << "String to compute: " << stringToCompute << std::endl;
            symbol = Lexer::readNextSymbol(stringToCompute);

            if (symbol == NULL) {
                // TODO : Warning/Error : unknown symbol
                break;
            }
            else
            {
                // TODO : Compute symbol
                computeNewSymbol(symbol);
            }

        }

    }

    file.close();
}

void Automaton::computeNewSymbol(Symbol * symbol)
{
    stackSymbols.push(symbol);
    stackStates.top()->transition(*this, symbol);
}

void Automaton::reduction(int reductionSize, Symbol * unterminalSymbol) {
    // TODO : refaire
    std::list<Symbol*> symbolsToCompute;

    for (int i=0, maxI = reductionSize - 1; i <= maxI; ++i) {
        stackStates.pop();

        if (i != maxI) {
            symbolsToCompute.push_back(stackSymbols.top());
        } else {
            Symbol * activeSymbol = stackSymbols.top();
            activeSymbol->computeSublistSymbols(symbolsToCompute);
            listActiveSymbols.push_back(activeSymbol);
        }

        stackSymbols.pop();
    }

    //stackStates.push(newState);
}

void Automaton::transition(Symbol * symbol, State * newState) {
    stackStates.push(newState);
}