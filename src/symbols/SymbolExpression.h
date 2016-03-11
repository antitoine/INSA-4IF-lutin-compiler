#if ! defined ( SYMBOLEXPRESSION )
#define SYMBOLEXPRESSION

#include "symbol.h"
#include "../automaton.h"

class SymbolExpression : public Symbol
{
public:
    SymbolExpression(enum symbolIdTable idSymbol);
    virtual float eval(std::map<Symbol*, StructVar> & dicoVariables);

protected:

};

#endif
