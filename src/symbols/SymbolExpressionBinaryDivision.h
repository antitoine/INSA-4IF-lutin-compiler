#if ! defined ( SYMBOLEXPRESSIONBINARYDIVISION )
#define SYMBOLEXPRESSIONBINARYDIVISION

#include "SymbolExpressionBinary.h"

class SymbolExpressionBinaryDivision : SymbolExpressionBinary
{
public:
    SymbolExpressionBinaryDivision();
    float eval(std::map<Symbol*, StructVar> & dicoVariables);


protected:

};

#endif
