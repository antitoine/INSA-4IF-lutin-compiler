#if ! defined ( SYMBOLEXPRESSIONBINARYSOUSTRACT )
#define SYMBOLEXPRESSIONBINARYSOUSTRACT

#include "SymbolExpressionBinary.h"

class SymbolExpressionBinarySoustract : public SymbolExpressionBinary
{
public:
    SymbolExpressionBinarySoustract();
    float eval(map<string, StructVar*>& dicoVariables);

protected:

};

#endif
