#if !defined ( SYMBOLINSTRUCTIONAFFECT )
#define SYMBOLINSTRUCTIONAFFECT

#include "SymbolInstruction.h"
#include "SymbolExpression.h"
#include "SymbolVariable.h"

using namespace std;

/**
 * Class representing the affectation (x := E;)
 */
class SymbolInstructionAffect : public SymbolInstruction {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolInstructionAffect();

    SymbolInstructionAffect(SymbolVariable *variable);

    virtual ~SymbolInstructionAffect();

    virtual string toString() const;

    void execute(map<string, StructVar *> &dicoVariables);

    virtual void affectExpression(SymbolExpression *expression);

    Symbol *optimize(map<string, StructVar *> &dicoVariables);

    virtual void check(map<string, StructVar *> &dicoVariables);

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /**
     * The expression to affect to the variable.
     */
    SymbolExpression *symbolExpression;

    /**
     * The variable to update the value.
     */
    SymbolVariable *symbolVariable;
};

#endif
