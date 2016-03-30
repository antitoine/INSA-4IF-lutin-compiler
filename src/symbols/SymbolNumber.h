#if ! defined ( SYMBOLNUMBER )
#define SYMBOLNUMBER

#include "SymbolExpression.h"

using namespace std;

/**
 * Class representing a numeric symbol.
 */
class SymbolNumber : public SymbolExpression
{
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolNumber();
    SymbolNumber(string stringValue);
    SymbolNumber(float value);
    virtual ~SymbolNumber();

    virtual string toString() const;
    float eval(map<string, StructVar*>& dicoVariables);
    float eval() const;

    static Symbol * analyse(string & stringToAnalyse, string & stringSymbolDetected);
    virtual list<Error*> * checkEval(map<string, StructVar*>& dicoVariables);

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /** Numeric value associated with the symbol. */
    float value;
};

#endif
