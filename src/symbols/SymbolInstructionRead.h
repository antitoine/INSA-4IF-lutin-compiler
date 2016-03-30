#if !defined ( SYMBOLINSTRUCTIONREAD )
#define SYMBOLINSTRUCTIONREAD

#include "SymbolInstruction.h"
#include "SymbolVariable.h"

using namespace std;

/**
 * Class representing the read instruction (lire x;)
 */
class SymbolInstructionRead : public SymbolInstruction {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolInstructionRead();

    virtual ~SymbolInstructionRead();

    void execute(map<string, StructVar *> &dicoVariables);

    virtual string toString() const;

    virtual void affectExpression(SymbolExpression *expression);

    static Symbol *analyse(string &stringToAnalyse, string &stringSymbolDetected);

    virtual void check(map<string, StructVar *> &dicoVariables);

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /** The variable to update after the read operation. */
    SymbolVariable *symbolVariable;
};

#endif
