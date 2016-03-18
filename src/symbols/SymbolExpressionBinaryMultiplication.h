#if ! defined ( SYMBOLEXPRESSIONBINARYMULTIPLICATION )
#define SYMBOLEXPRESSIONBINARYMULTIPLICATION

#include "SymbolExpressionBinary.h"

class SymbolExpressionBinaryMultiplication : public SymbolExpressionBinary
{
public:
    SymbolExpressionBinaryMultiplication();
    virtual std::string toString() const;
    float eval(map<string, StructVar*>& dicoVariables);


protected:

};

#endif
