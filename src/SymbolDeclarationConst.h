#include "SymbolDeclaration.h"

#if ! defined ( SYMBOLDECLARATIONCONST )
#define SYMBOLDECLARATIONCONST 

class SymbolDeclarationConst : public SymbolDeclaration
{
public:
    SymbolDeclarationConst();
    static Symbol * analyse(const std::string & stringToAnalyse, std::string & stringSymbolDetected);

protected:

};

#endif
