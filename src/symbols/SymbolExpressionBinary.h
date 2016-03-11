#if !defined ( SYMBOLEXPRESSIONBINARY )
#define SYMBOLEXPRESSIONBINARY

#include "SymbolExpression.h"

class SymbolExpressionBinary : public SymbolExpression {
public:
    SymbolExpressionBinary(enum symbolIdTable idSymbol);

    virtual float eval(std::map<Symbol *, StructVar> &dicoVariables) = 0;


protected:
    SymbolExpression *firstOperand;
    SymbolExpression *secondOperand;

};

#endif
