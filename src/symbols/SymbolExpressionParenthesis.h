#if ! defined ( SYMBOLEXPRESSIONPARENTHESIS )
#define SYMBOLEXPRESSIONPARENTHESIS

#include "SymbolExpression.h"

class SymbolExpressionParenthesis : public SymbolExpression
{
public:
    SymbolExpressionParenthesis();
    float eval(std::map<Symbol*, StructVar> & dicoVariables);
    void setExpression(SymbolExpression * expression);

protected:
    SymbolExpression* symbolExpression;
};

#endif
