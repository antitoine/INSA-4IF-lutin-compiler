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
    virtual std::string toString() const;
    void execute(map<string, StructVar*>& dicoVariables);
    virtual void affectExpression(SymbolExpression * expression);

protected:
    SymbolExpression* symbolExpression;
    SymbolVariable* symbolVariable;

};

#endif
