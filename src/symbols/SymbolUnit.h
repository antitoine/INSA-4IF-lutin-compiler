#if ! defined ( UNITSYMBOL )
#define UNITSYMBOL

#include "Symbol.h"

class SymbolUnit : public Symbol
{
public:
    SymbolUnit(enum TypeSymbolUnit);
    virtual ~SymbolUnit();

    virtual std::string toString() const;
    static Symbol * analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected);

protected:
};

#endif
