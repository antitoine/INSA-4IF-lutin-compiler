#ifndef LUTIN_COMPILER_LEXER_H
#define LUTIN_COMPILER_LEXER_H

#include <string>
#include "symbols/Symbol.h"

class Lexer {

public:
    static Symbol * readNextSymbol(std::string & stringToRead, map<string, StructVar*>& dicoVariables);

    static Symbol *analyse(string &stringToRead, string stringSymbolDetected);
};


#endif //LUTIN_COMPILER_LEXER_H
