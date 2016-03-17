#if ! defined ( SYMBOLEXPRESSIONBINARYMULTIPLICATION )
#define SYMBOLEXPRESSIONBINARYMULTIPLICATION

#include "SymbolExpressionBinary.h"

class SymbolExpressionBinaryMultiplication : public SymbolExpressionBinary
{
public:
    SymbolExpressionBinaryMultiplication();
    float eval(map<string, StructVar*>& dicoVariables);


protected:

};

#endif
