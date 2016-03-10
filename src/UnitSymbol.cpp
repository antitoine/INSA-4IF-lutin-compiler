//#include <boost>
#include <map>
#include "UnitSymbol.h"

using namespace std;

UnitSymbol::UnitSymbol(enum unitSymbolIdTable uSymbol):Symbol(S_UNIT)
{
    type = uSymbol;
}
