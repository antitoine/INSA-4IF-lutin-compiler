#if ! defined ( SYMBOLEXPRESSIONBINARYSOUSTRACT )
#define SYMBOLEXPRESSIONBINARYSOUSTRACT

#include "SymbolExpressionBinary.h"

class SymbolExpressionBinarySoustract : public SymbolExpressionBinary
{
public:
    SymbolExpressionBinarySoustract();
    float eval(std::map<Symbol*, StructVar> & dicoVariables);

protected:

};

#endif
