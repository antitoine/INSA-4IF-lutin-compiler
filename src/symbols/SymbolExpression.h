#if ! defined ( SYMBOLEXPRESSION )
#define SYMBOLEXPRESSION

#include "symbol.h"
#include "../automaton.h"

class SymbolExpression : public Symbol
{
public:
    SymbolExpression(enum symbolIdTable idSymbol);
    virtual float eval(map<string, StructVar*>& dicoVariables) = 0;
    virtual bool isPersistent() const;

protected:

};

#endif
