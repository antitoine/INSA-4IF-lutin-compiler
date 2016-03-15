#if ! defined ( SYMBOLDECLARATIONVAR )
#define SYMBOLDECLARATIONVAR

#include "SymbolDeclaration.h"

class SymbolVariable;

using namespace std;

class SymbolDeclarationVar : public SymbolDeclaration
{
public:
    SymbolDeclarationVar();
    virtual string toString();
    static Symbol * analyse(string & stringToAnalyse, string & stringSymbolDetected);
    void execute(map<Symbol*, StructVar> & dicoVariables);

    void addVariable(SymbolVariable *pVariable);

protected:

private:
    list<SymbolVariable*> variables;
};

#endif
