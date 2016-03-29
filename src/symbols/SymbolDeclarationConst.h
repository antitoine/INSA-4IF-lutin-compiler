#if ! defined ( SYMBOLDECLARATIONCONST )
#define SYMBOLDECLARATIONCONST

#include "SymbolDeclaration.h"
#include "SymbolVariable.h"

struct comparatorBySymbolVariablePt {
    bool operator()(const SymbolVariable* a, const SymbolVariable*  b) const {
        return a->getName() < b->getName();
    }
};

class SymbolDeclarationConst : public SymbolDeclaration
{
public:
    SymbolDeclarationConst();
    virtual ~SymbolDeclarationConst();

    virtual std::string toString() const;
    void detachConstant(map<string, StructVar*>& dicoVariables);
    static Symbol * analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected);
    void execute(map<string, StructVar*>& dicoVariables);

    void addConstant(SymbolVariable *pVariable);
    void addConstantValue(float constantValue, map<string, StructVar*>& dicoVariables);

    virtual void check(map<string, StructVar*>& dicoVariables);

private:
    std::map<SymbolVariable*, float, comparatorBySymbolVariablePt> constants;
    SymbolVariable * temporaryPtVariable;

};

#endif
