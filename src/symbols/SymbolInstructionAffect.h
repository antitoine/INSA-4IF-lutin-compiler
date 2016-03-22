#if ! defined ( SYMBOLINSTRUCTIONAFFECT )
#define SYMBOLINSTRUCTIONAFFECT

#include "SymbolInstruction.h"
#include "SymbolExpression.h"
#include "SymbolVariable.h"


class SymbolInstructionAffect : public SymbolInstruction
{
public:
    SymbolInstructionAffect();
    SymbolInstructionAffect(SymbolVariable * variable);
    virtual ~SymbolInstructionAffect();

    virtual std::string toString() const;
    void execute(map<string, StructVar*>& dicoVariables);
    virtual void affectExpression(SymbolExpression * expression);

    virtual void check(map<string, StructVar*>& dicoVariables);

protected:
    SymbolExpression* symbolExpression;
    SymbolVariable* symbolVariable;

};

#endif
