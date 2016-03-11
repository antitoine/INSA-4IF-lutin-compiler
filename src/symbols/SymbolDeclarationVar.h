#if ! defined ( SYMBOLDECLARATIONVAR )
#define SYMBOLDECLARATIONVAR

#include "SymbolDeclaration.h"
#include "SymbolVariable.h"

class SymbolDeclarationVar : public SymbolDeclaration
{
public:
    SymbolDeclarationVar();
    virtual std::string toString();
    static Symbol * analyse(const std::string & stringToAnalyse, std::string & stringSymbolDetected);
    virtual void computeSublistSymbols(const std::list<Symbol*> & symbolsToCompute);
    void execute(std::map<Symbol*, StructVar> & dicoVariables);


protected:

private:
    std::list<SymbolVariable*> variables;
};

#endif
