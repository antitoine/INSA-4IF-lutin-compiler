#if ! defined SYMBOLINSTRUCTION
#define SYMBOLINSTRUCTION


#include <map>

#include "Symbol.h"
#include "../Automaton.h"

class SymbolInstruction : public Symbol
{
public:
    SymbolInstruction(enum symbolIdTable idSymbol);
    virtual ~SymbolInstruction();

    virtual std::string toString() const = 0;
    virtual void execute(map<string, StructVar*>& dicoVariables) = 0;
    virtual bool isPersistent() const;
    virtual void affectExpression(SymbolExpression * expression) = 0;

protected:

};

#endif
