#if ! defined SYMBOLDECLARATION
#define SYMBOLDECLARATION

#include "../StructVar.h"
#include "../Automaton.h"
#include "Symbol.h"

class SymbolDeclaration : public Symbol
{
public:
    SymbolDeclaration(enum symbolIdTable idSymbol);
    SymbolDeclaration();
    virtual std::string toString();
    virtual void execute(map<string, StructVar*>& dicoVariables) = 0 ;
    virtual bool isPersistent() const;

protected:
};

#endif
