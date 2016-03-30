#if !defined ( SYMBOLEXPRESSIONPARENTHESIS )
#define SYMBOLEXPRESSIONPARENTHESIS

#include "SymbolExpression.h"

using namespace std;

/**
 * Class representing a parenthesis expression (E).
 */
class SymbolExpressionParenthesis : public SymbolExpression {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolExpressionParenthesis();

    virtual ~SymbolExpressionParenthesis();

    virtual string toString() const;

    float eval(map<string, StructVar *> &dicoVariables);

    virtual list<Error *> *checkEval(map<string, StructVar *> &dicoVariables);

    virtual SymbolExpression *optimizeExpression(map<string, StructVar *> &dicoVariables);

    virtual void detachExpressions();

    /**
     * Associate an expression with the current parenthesis expression.
     * @param expression Expression to associate.
     */
    void setExpression(SymbolExpression *expression);

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /**
     * The expression associated with the current parenthesis expression.
     */
    SymbolExpression *symbolExpression;
};

#endif
