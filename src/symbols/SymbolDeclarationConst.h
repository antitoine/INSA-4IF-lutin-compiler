#if ! defined ( SYMBOLDECLARATIONCONST )
#define SYMBOLDECLARATIONCONST

#include "SymbolDeclaration.h"
#include "SymbolVariable.h"

class SymbolDeclarationConst : public SymbolDeclaration
{
public:
    SymbolDeclarationConst();
    virtual std::string toString();
    static Symbol * analyse(const std::string & stringToAnalyse, std::string & stringSymbolDetected);
    void execute(std::map<Symbol*, StructVar> & dicoVariables);

protected:
    std::map<SymbolVariable*, float> constants;

private:

};

#endif
