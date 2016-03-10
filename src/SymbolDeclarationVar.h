#if ! defined ( SYMBOLDECLARATIONVAR ) 
#define SYMBOLDECLARATIONVAR 

#include "SymbolDeclaration.h"

class SymbolDeclarationVar : public SymbolDeclaration
{
public:
    SymbolDeclarationVar();
    virtual std::string toString();
    static Symbol * analyse(const std::string & stringToAnalyse, std::string & stringSymbolDetected);

protected:

};

#endif
