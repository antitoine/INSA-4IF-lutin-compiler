#if ! defined ( SYMBOLEXPRESSIONPARENTHESIS )
#define SYMBOLEXPRESSIONPARENTHESIS

#include "SymbolExpression.h"

class SymbolExpressionParenthesis : public SymbolExpression
{
public:
    SymbolExpressionParenthesis();
    virtual std::string toString() const;
    float eval(map<string, StructVar*>& dicoVariables);
    void setExpression(SymbolExpression * expression);

protected:
    SymbolExpression* symbolExpression;
};

#endif
