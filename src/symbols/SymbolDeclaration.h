#if ! defined SYMBOLDECLARATION
#define SYMBOLDECLARATION

#include "symbol.h"
#include "../automaton.h"

class SymbolDeclaration : public Symbol
{
public:
    SymbolDeclaration(enum symbolIdTable idSymbol);
    SymbolDeclaration();
    virtual std::string toString();
    virtual void execute(std::map<Symbol*, StructVar> & dicoVariables);


protected:
};

#endif
