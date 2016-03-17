#ifndef LUTIN_COMPILER_SYMBOLUNTERMINAL_H
#define LUTIN_COMPILER_SYMBOLUNTERMINAL_H


#include "symbol.h"

class SymbolUnterminal : public Symbol
{
public:
    SymbolUnterminal(enum TypeSymbolUnterminal);

    virtual std::string toString();

protected:
};


#endif //LUTIN_COMPILER_SYMBOLUNTERMINAL_H
