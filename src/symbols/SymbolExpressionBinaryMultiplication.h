#if ! defined ( SYMBOLEXPRESSIONBINARYMULTIPLICATION )
#define SYMBOLEXPRESSIONBINARYMULTIPLICATION

#include "SymbolExpressionBinary.h"

class SymbolExpressionBinaryMultiplication : SymbolExpressionBinary
{
public:
    SymbolExpressionBinaryMultiplication();
    float eval(std::map<Symbol*, StructVar> & dicoVariables);


protected:

};

#endif
