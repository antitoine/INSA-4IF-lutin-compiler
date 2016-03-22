#ifndef LUTIN_COMPILER_LEXER_H
#define LUTIN_COMPILER_LEXER_H

#include <string>
#include "symbols/Symbol.h"

class Lexer {

public:
    static Symbol *readNextSymbol(string &stringToRead, string & stringSymbolDetected,
                                  int linePosition, int charPosition);
};


#endif //LUTIN_COMPILER_LEXER_H
