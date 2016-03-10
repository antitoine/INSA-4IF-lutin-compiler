#ifndef LUTIN_COMPILER_LEXER_H
#define LUTIN_COMPILER_LEXER_H

#include <string>
#include "symbols/symbol.h"

class Lexer {

public:
    static Symbol * readNextSymbol(std::string & stringToRead);
};


#endif //LUTIN_COMPILER_LEXER_H
