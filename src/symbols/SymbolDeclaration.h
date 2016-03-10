#if ! defined SYMBOLDECLARATION
#define SYMBOLDECLARATION

#include "symbol.h"

class SymbolDeclaration : public Symbol
{
public:
    SymbolDeclaration(enum symbolIdTable idSymbol);
    SymbolDeclaration();
    virtual std::string toString();

protected:
};

#endif
