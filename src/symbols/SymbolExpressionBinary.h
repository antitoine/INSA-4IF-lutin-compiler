#if !defined ( SYMBOLEXPRESSIONBINARY )
#define SYMBOLEXPRESSIONBINARY

#include "../exceptions/Error.h"
#include "SymbolExpression.h"

using namespace std;

/**
 * Abstract class representing a binary operator (with 2 operands).
 */
class SymbolExpressionBinary : public SymbolExpression {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolExpressionBinary(enum symbolIdTable idSymbol);

    virtual ~SymbolExpressionBinary();

    virtual string toString() const = 0;

    virtual float eval(map<string, StructVar *> &dicoVariables) = 0;

    virtual list<Error *> *checkEval(map<string, StructVar *> &dicoVariables);

    virtual SymbolExpression *optimizeExpression(map<string, StructVar *> &dicoVariables);

    virtual void detachExpressions();

    /**
     * Set the left and right operands to the current binary operator.
     * @leftOperand The first operand to affect.
     * @rightOperand The second operand to affect.
     */
    virtual void setOperands(SymbolExpression *leftOperand, SymbolExpression *rightOperand);

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /**
     * Left operand of the binary operator.
     */
    SymbolExpression *firstOperand;

    /**
     * Right operand of the binary operator.
     */
    SymbolExpression *secondOperand;
};

#endif
