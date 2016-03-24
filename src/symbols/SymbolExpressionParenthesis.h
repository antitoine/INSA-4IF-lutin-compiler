#if ! defined ( SYMBOLEXPRESSIONPARENTHESIS )
#define SYMBOLEXPRESSIONPARENTHESIS

#include "SymbolExpression.h"

class SymbolExpressionParenthesis : public SymbolExpression
{
public:
    SymbolExpressionParenthesis();
    virtual ~SymbolExpressionParenthesis();

    virtual std::string toString() const;
    float eval(map<string, StructVar*>& dicoVariables);
    void setExpression(SymbolExpression * expression);
    virtual list<Error*> * checkEval(map<string, StructVar*>& dicoVariables);
    virtual SymbolExpression * optimizeExpression(map<string, StructVar*>& dicoVariables);

    virtual void detachExpressions();


protected:
    SymbolExpression* symbolExpression;
};

#endif
