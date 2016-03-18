#if ! defined ( SYMBOLEXPRESSIONBINARYSUBSTRACT )
#define SYMBOLEXPRESSIONBINARYSUBSTRACT

#include "SymbolExpressionBinary.h"

class SymbolExpressionBinarySubstract : public SymbolExpressionBinary
{
public:
    SymbolExpressionBinarySubstract();
    virtual std::string toString() const;
    float eval(map<string, StructVar*>& dicoVariables);

protected:

};

#endif
