#if ! defined ( SYMBOLDECLARATIONVAR )
#define SYMBOLDECLARATIONVAR

#include "SymbolDeclaration.h"
#include "SymbolVariable.h"

class SymbolVariable;

struct VarListEntity {
    SymbolVariable * ptVariable;
    int posLine;
    int posChar;
};

class SymbolDeclarationVar : public SymbolDeclaration
{
public:
    SymbolDeclarationVar();
    virtual ~SymbolDeclarationVar();

    virtual string toString() const;
    static Symbol * analyse(string & stringToAnalyse, string & stringSymbolDetected);
    void execute(map<string, StructVar*>& dicoVariables);

    void addVariable(SymbolVariable *pVariable, map<string, StructVar*>& dicoVariables);

protected:

private:
    list<SymbolVariable*> variables;
};

#endif
