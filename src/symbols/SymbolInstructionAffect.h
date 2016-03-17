#if ! defined ( SYMBOLINSTRUCTIONAFFECT )
#define SYMBOLINSTRUCTIONAFFECT

#include "SymbolInstruction.h"
#include "SymbolExpression.h"
#include "SymbolVariable.h"


class SymbolInstructionAffect : public SymbolInstruction
{
public:
    SymbolInstructionAffect();
    void execute(std::map<Symbol*, StructVar> & dicoVariables);

    virtual void affectExpression(SymbolExpression * expression);

protected:
    SymbolExpression* symbolExpression;
    SymbolVariable* symbolVariable;

};

#endif
