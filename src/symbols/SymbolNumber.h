#if ! defined ( SYMBOLNUMBER )
#define SYMBOLNUMBER

#include "SymbolExpression.h"

class SymbolNumber : public SymbolExpression
{
public:
    SymbolNumber();
    SymbolNumber(string stringValue);
    virtual ~SymbolNumber();

    virtual std::string toString() const;
    float eval(map<string, StructVar*>& dicoVariables);
    float eval() const;

    static Symbol * analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected);
    virtual list<Error*> * checkEval(map<string, StructVar*>& dicoVariables);

    static string removeLeadingZeroes(string number);

protected:
    float value;
};

#endif
