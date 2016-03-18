#if ! defined ( SYMBOLEXPRESSIONBINARYADD )
#define SYMBOLEXPRESSIONBINARYADD

#include "SymbolExpressionBinary.h"

class SymbolExpressionBinaryAdd : public SymbolExpressionBinary
{
public:
    SymbolExpressionBinaryAdd();
    virtual std::string toString() const;
    float eval(map<string, StructVar*>& dicoVariables);

protected:

};

#endif
