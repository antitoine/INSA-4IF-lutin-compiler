#if ! defined SYMBOLINSTRUCTION
#define SYMBOLINSTRUCTION


#include <map>

#include "symbol.h"
#include "../automaton.h"

class SymbolInstruction : public Symbol
{
public:
    SymbolInstruction(enum symbolIdTable idSymbol);
    virtual void execute(std::map<Symbol*, StructVar> & dicoVariables) = 0;
    virtual bool isPersistent() const;

protected:

};

#endif
