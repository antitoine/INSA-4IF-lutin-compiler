#include <iostream>
#include "Lexer.h"
#include "symbols/SymbolDeclarationVar.h"
#include "symbols/SymbolDeclarationConst.h"
#include "symbols/SymbolUnit.h"
#include "symbols/SymbolNumber.h"
#include "symbols/SymbolInstructionWrite.h"
#include "symbols/SymbolInstructionRead.h"
#include "symbols/RegexSymbol.h"
#include "exceptions/ErrorLexicalUnknownSymbol.h"

Symbol * Lexer::readNextSymbol(std::string & stringToRead, map<string, StructVar*>& dicoVariables, int & charPos)
{
    Symbol * symbol = NULL;
    std::string symbolDetected;

    // Test to find a symbol, by priority order
    if ((symbol = SymbolDeclarationVar::analyse(stringToRead, symbolDetected)) != NULL);
    else if ((symbol = SymbolDeclarationConst::analyse(stringToRead, symbolDetected)) != NULL);
    else if ((symbol = SymbolInstructionWrite::analyse(stringToRead, symbolDetected)) != NULL);
    else if ((symbol = SymbolInstructionRead::analyse(stringToRead, symbolDetected)) != NULL);

    else if ((symbol = SymbolUnit::analyse(stringToRead, symbolDetected)) != NULL);
    else if ((symbol = SymbolVariable::analyse(stringToRead, symbolDetected, dicoVariables)) != NULL);
    else if ((symbol = SymbolNumber::analyse(stringToRead, symbolDetected)) != NULL);


    // If a symbol is found
    if (symbol != NULL) {
        charPos += symbolDetected.length();

    } else {
        MatchingResult result = RegexSymbol::matches(stringToRead, Regex::Symbol::UNKNOWN_SYMBOL);

        if (result.matched) {
            stringToRead = result.stringConsumed;
            charPos += result.stringMatched.length();
            throw ErrorLexicalUnknownSymbol(result.stringMatched);
        }
    }

    return symbol;
}

