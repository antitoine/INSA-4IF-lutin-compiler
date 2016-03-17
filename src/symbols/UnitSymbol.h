#if ! defined ( UNITSYMBOL )
#define UNITSYMBOL

#include "Symbol.h"

class UnitSymbol : public Symbol
{
public:
    UnitSymbol(enum TypeSymbolUnit);

    virtual std::string toString();
    static Symbol * analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected);

protected:
};

#endif
