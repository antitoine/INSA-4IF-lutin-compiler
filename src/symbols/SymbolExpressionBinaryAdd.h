#if ! defined ( SYMBOLEXPRESSIONBINARYADD )
#define SYMBOLEXPRESSIONBINARYADD

#include "SymbolExpressionBinary.h"

class SymbolExpressionBinaryAdd : public SymbolExpressionBinary
{
public:
    SymbolExpressionBinaryAdd();
    float eval(std::map<Symbol*, StructVar> & dicoVariables);


protected:

};

#endif
