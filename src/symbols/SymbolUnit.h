#if !defined ( UNITSYMBOL )
#define UNITSYMBOL

#include "Symbol.h"

using namespace std;

/**
 * Class representing a unit symbol, i.e. a symbol associated with a single character.
 */
class SymbolUnit : public Symbol {
// METHODS -------------------------------------------------------------------------------------------------------------    
public:
    SymbolUnit(enum TypeSymbolUnit);

    virtual ~SymbolUnit();

    virtual string toString() const;

    static Symbol *analyse(string &stringToAnalyse, string &stringSymbolDetected);
};

#endif
