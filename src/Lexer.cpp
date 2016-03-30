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

Symbol *Lexer::readNextSymbol(string &stringToRead, string &stringSymbolDetected, int linePosition, int charPosition) {
    Symbol *symbol = NULL;

    // Test to find a symbol, by priority order
    if ((symbol = SymbolDeclarationVar::analyse(stringToRead, stringSymbolDetected)) != NULL);
    else if ((symbol = SymbolDeclarationConst::analyse(stringToRead, stringSymbolDetected)) != NULL);
    else if ((symbol = SymbolInstructionWrite::analyse(stringToRead, stringSymbolDetected)) != NULL);
    else if ((symbol = SymbolInstructionRead::analyse(stringToRead, stringSymbolDetected)) != NULL);
    else if ((symbol = SymbolUnit::analyse(stringToRead, stringSymbolDetected)) != NULL);
    else if ((symbol = SymbolVariable::analyse(stringToRead, stringSymbolDetected)) != NULL);
    else if ((symbol = SymbolNumber::analyse(stringToRead, stringSymbolDetected)) != NULL);

    // If a symbol is not found, catch the unknown symbols.
    if (symbol == NULL) {
        MatchingResult result = RegexSymbol::matches(stringToRead, Regex::Symbol::UNKNOWN_SYMBOL);

        if (result.matched) {
            stringToRead = result.stringConsumed;
            stringSymbolDetected = result.stringMatched;
            throw ErrorLexicalUnknownSymbol(result.stringMatched, linePosition, charPosition);
        }
    }

    return symbol;
}

