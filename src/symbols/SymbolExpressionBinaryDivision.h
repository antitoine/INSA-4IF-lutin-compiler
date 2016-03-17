#if ! defined ( SYMBOLEXPRESSIONBINARYDIVISION )
#define SYMBOLEXPRESSIONBINARYDIVISION

#include "SymbolExpressionBinary.h"

class SymbolExpressionBinaryDivision : public SymbolExpressionBinary
{
public:
    SymbolExpressionBinaryDivision();
    float eval(map<string, StructVar*>& dicoVariables);


protected:

};

#endif
