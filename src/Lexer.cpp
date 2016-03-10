//
// Created by pierre on 10/03/16.
//

#include <iostream>
#include "Lexer.h"
#include "symbols/SymbolDeclarationVar.h"
#include "symbols/SymbolDeclarationConst.h"
#include "symbols/UnitSymbol.h"

Symbol * Lexer::readNextSymbol(std::string & stringToRead)
{
    Symbol * symbol = NULL;
    std::string symbolDetected;

    // Test to find a symbol, by priority order
    if ((symbol = SymbolDeclarationVar::analyse(stringToRead, symbolDetected)) != NULL);
    else if ((symbol = SymbolDeclarationConst::analyse(stringToRead, symbolDetected)) != NULL);
    else if ((symbol = SymbolVariable::analyse(stringToRead, symbolDetected)) != NULL);
    else if ((symbol = UnitSymbol::analyse(stringToRead, symbolDetected)) != NULL);

    // If a symbol is found
    if (symbol != NULL) {
        std::cout << "Symbol detected: " << symbolDetected << std::endl;

        // Reduce the string
        stringToRead.erase(0, symbolDetected.length());
    }

    return symbol;
}