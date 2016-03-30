#if !defined SYMBOLDECLARATION
#define SYMBOLDECLARATION

#include "../StructVar.h"
#include "../Automaton.h"
#include "Symbol.h"

/**
 * Abstract class representing a variable declaration.
 */
class SymbolDeclaration : public Symbol {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolDeclaration();

    SymbolDeclaration(enum symbolIdTable idSymbol);

    virtual ~SymbolDeclaration();

    virtual bool isPersistent() const;

    virtual void execute(map<string, StructVar *> &dicoVariables) = 0;

    virtual void check(map<string, StructVar *> &dicoVariables);

    virtual std::string toString() const = 0;

protected:
};

#endif
