#if !defined SYMBOLINSTRUCTION
#define SYMBOLINSTRUCTION

#include <map>

#include "Symbol.h"
#include "../Automaton.h"

using namespace std;

/**
 * Abstract class representing an instruction symbol.
 */
class SymbolInstruction : public Symbol {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolInstruction(enum symbolIdTable idSymbol);

    virtual ~SymbolInstruction();

    virtual string toString() const = 0;

    virtual void execute(map<string, StructVar *> &dicoVariables) = 0;

    virtual bool isPersistent() const;

    /**
     * Abstract method: Affect the expression passed by parameter to the current instruction.
     * @param expression The expression to affect.
     */
    virtual void affectExpression(SymbolExpression *expression) = 0;
};

#endif
