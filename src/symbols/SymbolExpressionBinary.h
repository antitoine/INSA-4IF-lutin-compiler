#if !defined ( SYMBOLEXPRESSIONBINARY )
#define SYMBOLEXPRESSIONBINARY

#include "SymbolExpression.h"

class SymbolExpressionBinary : public SymbolExpression {
public:
    SymbolExpressionBinary(enum symbolIdTable idSymbol);

    virtual float eval(std::map<string, StructVar*> &dicoVariables) = 0;

    virtual void setOperands(SymbolExpression * leftOperand, SymbolExpression * rightOperand);

protected:
    SymbolExpression *firstOperand;
    SymbolExpression *secondOperand;

};

#endif
