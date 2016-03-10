#if ! defined ( UNITSYMBOL )
#define UNITSYMBOL

#include "symbol.h"

class UnitSymbol : public Symbol
{
public:
    UnitSymbol(enum unitSymbolIdTable);

protected:
    enum unitSymbolIdTable type;
};

#endif
