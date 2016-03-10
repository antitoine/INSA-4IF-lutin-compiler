//#include <boost>
#include <map>
#include <iostream>
#include "UnitSymbol.h"
#include "SymbolVariable.h"

using namespace std;

UnitSymbol::UnitSymbol(enum unitSymbolIdTable uSymbol):Symbol(uSymbol)
{
}

std::string UnitSymbol::toString() {
    std::cout << "Symbol ID (id: " << id << ")" << std::endl;
}

Symbol * UnitSymbol::analyse(const std::string & stringToAnalyse, std::string & stringSymbolDetected) {

    char firstCharacter = stringToAnalyse.c_str()[0];

    // TODO
    switch (firstCharacter) {
        case ';':
            return new UnitSymbol(SU_SEMICOLON);
    }

    return NULL;
}
