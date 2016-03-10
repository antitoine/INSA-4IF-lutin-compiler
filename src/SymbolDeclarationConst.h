#if ! defined ( SYMBOLDECLARATIONCONST )
#define SYMBOLDECLARATIONCONST

#include "SymbolDeclaration.h"

class SymbolDeclarationConst : public SymbolDeclaration
{
public:
    SymbolDeclarationConst();
    static Symbol * analyse(const std::string & stringToAnalyse, std::string & stringSymbolDetected);

protected:

};

#endif
