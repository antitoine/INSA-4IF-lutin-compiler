#if ! defined ( SYMBOLEXPRESSIONBINARYMULTIPLICATION )
#define SYMBOLEXPRESSIONBINARYMULTIPLICATION

#include "SymbolExpressionBinary.h"

class SymbolExpressionBinaryMultiplication : public SymbolExpressionBinary
{
public:
    SymbolExpressionBinaryMultiplication();
    float eval(std::map<Symbol*, StructVar> & dicoVariables);


protected:

};

#endif
