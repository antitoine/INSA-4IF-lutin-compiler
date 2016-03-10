#if ! defined ( SYMBOLDECLARATIONCONST )
#define SYMBOLDECLARATIONCONST

#include "SymbolDeclaration.h"

class SymbolDeclarationConst : public SymbolDeclaration
{
public:
    SymbolDeclarationConst();
    virtual std::string toString();
    static Symbol * analyse(const std::string & stringToAnalyse, std::string & stringSymbolDetected);

protected:

};

#endif
