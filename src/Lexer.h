#ifndef LUTIN_COMPILER_LEXER_H
#define LUTIN_COMPILER_LEXER_H

#include <string>
#include "symbols/Symbol.h"

/**
 * Static class used to read a lexical symbol, related to a Symbol class.
 */
class Lexer {

public:
    /**
     * Read the next symbol found in stringToRead, related to a Symbol class.
     * @param stringToRead The string where a symbol must be found. If a symbol is found, stringToRead is reduced.
     * @param stringSymbolDetected If a symbol is found, affect its string value to this param.
     * @param linePosition The current position in the file, used for errors.
     * @param charPosition The current character column in the file, used for errors.
     */
    static Symbol *readNextSymbol(string &stringToRead, string &stringSymbolDetected, int linePosition,
                                  int charPosition);
};

#endif //LUTIN_COMPILER_LEXER_H
