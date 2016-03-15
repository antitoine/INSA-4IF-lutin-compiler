#if ! defined ( SYMBOLDECLARATIONCONST )
#define SYMBOLDECLARATIONCONST

#include "SymbolDeclaration.h"
#include "SymbolVariable.h"

class SymbolDeclarationConst : public SymbolDeclaration
{
public:
    SymbolDeclarationConst();
    virtual std::string toString();
    static Symbol * analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected);
    void execute(std::map<Symbol*, StructVar> & dicoVariables);

    void addConstant(SymbolVariable *pVariable);
    void addConstantValue(float constantValue);

protected:
    std::map<SymbolVariable*, float> constants;

private:
    SymbolVariable * temporaryPtVariable;
};

#endif
