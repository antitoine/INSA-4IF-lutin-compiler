#if ! defined ( UNITSYMBOL )
#define UNITSYMBOL

#include "symbol.h"

class UnitSymbol : public Symbol
{
public:
    UnitSymbol(enum unitSymbolIdTable);

    virtual std::string toString();
    static Symbol * analyse(const std::string & stringToAnalyse, std::string & stringSymbolDetected);

protected:
};

#endif
