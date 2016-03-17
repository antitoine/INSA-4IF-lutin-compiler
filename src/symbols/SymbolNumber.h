#if ! defined ( SYMBOLNUMBER )
#define SYMBOLNUMBER

#include "SymbolExpression.h"

class SymbolNumber : public SymbolExpression
{
public:
    SymbolNumber();
    SymbolNumber(string stringValue);
    float eval(map<string, StructVar*>& dicoVariables);
    float getFloatValue() const;

    static Symbol * analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected);

protected:
    float value;
};

#endif
