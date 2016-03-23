#if ! defined ( SYMBOLEXPRESSIONBINARYDIVISION )
#define SYMBOLEXPRESSIONBINARYDIVISION

#include "SymbolExpressionBinary.h"

class SymbolExpressionBinaryDivision : public SymbolExpressionBinary
{
public:
    SymbolExpressionBinaryDivision();
    virtual ~SymbolExpressionBinaryDivision();

    virtual std::string toString() const;
    float eval(map<string, StructVar*>& dicoVariables);
    SymbolExpression * optimizeExpression(map<string, StructVar*>& dicoVariables);


protected:

};

#endif
