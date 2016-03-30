#if !defined ( SYMBOLEXPRESSION )
#define SYMBOLEXPRESSION

#include <list>
#include "Symbol.h"
#include "../Automaton.h"
#include "../exceptions/Error.h"

using namespace std;

/**
 * Abstract class representing an arithmetic expression.
 */
class SymbolExpression : public Symbol {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolExpression(enum symbolIdTable idSymbol);

    virtual ~SymbolExpression();

    virtual bool isPersistent() const;

    virtual string toString() const = 0;

    /**
     * Abstract method: eval the current expression to return its current value.
     * @param dicoVariables The map with the variables' status used by the program.
     * @return The current value of the expression.
     */
    virtual float eval(map<string, StructVar *> &dicoVariables) = 0;

    /**
     * Check the correctness of the expression and check if its value can be evaluated.
     * @param dicoVariables The map with the variables' status used by the program.@
     * @return List of errors (Exceptions) or NULL.
     */
    virtual list<Error *> *checkEval(map<string, StructVar *> &dicoVariables) = 0;

    /**
     * Try to optimize the expression.
     * @param dicoVariables The map with the variables' status used by the program.
     * @return Pointer to the optimized expression. Itself by default.
     */
    virtual SymbolExpression *optimizeExpression(map<string, StructVar *> &dicoVariables);

    /**
     * Detach the expressions associated with the current expression, to prevent deleting them in destructor.
     */
    virtual void detachExpressions();

protected:
};

#endif
