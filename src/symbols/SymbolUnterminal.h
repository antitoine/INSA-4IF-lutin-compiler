#ifndef LUTIN_COMPILER_SYMBOLUNTERMINAL_H
#define LUTIN_COMPILER_SYMBOLUNTERMINAL_H


#include "Symbol.h"

class SymbolUnterminal : public Symbol
{
public:
    SymbolUnterminal(enum TypeSymbolUnterminal);
    virtual ~SymbolUnterminal();
    virtual std::string toString() const;

protected:
};


#endif //LUTIN_COMPILER_SYMBOLUNTERMINAL_H
