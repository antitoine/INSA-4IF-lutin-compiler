#include <ostream>
#include <iostream>
#include <fstream>
#include "automaton.h"
#include "Lexer.h"

bool Automaton::readFile(std::string filename) {
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
    if (IActiveSymbol * newActiveSymbol = dynamic_cast<IActiveSymbol*>(symbol)) {
        activeSymbol = newActiveSymbol;
    }

    stackSymbols.push(symbol);
    stackStates.top()->transition(*this, symbol);
}
