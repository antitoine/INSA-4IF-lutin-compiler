#if ! defined ( SYMBOLEXPRESSION )
#define SYMBOLEXPRESSION

#include "Symbol.h"
#include "../Automaton.h"

class SymbolExpression : public Symbol
{
public:
    SymbolExpression(enum symbolIdTable idSymbol);
    virtual std::string toString() const = 0;
    virtual float eval(std::map<std::string, StructVar*>& dicoVariables) = 0;
    virtual bool isPersistent() const;

protected:

};

#endif
