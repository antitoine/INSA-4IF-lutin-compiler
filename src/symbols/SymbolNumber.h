#if ! defined ( SYMBOLNUMBER )
#define SYMBOLNUMBER

#include "SymbolExpression.h"

class SymbolNumber : public SymbolExpression
{
public:
    SymbolNumber();
    float eval(std::map<Symbol*, StructVar> & dicoVariables);


protected:
    float value;
};

#endif
