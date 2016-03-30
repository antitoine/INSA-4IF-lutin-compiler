#if !defined ( SYMBOLINSTRUCTIONWWRITE )
#define SYMBOLINSTRUCTIONWWRITE

#include "SymbolInstruction.h"

using namespace std;

/**
 * Class representing the write instruction (ecrire E;)
 */
class SymbolInstructionWrite : public SymbolInstruction {
// METHODS -------------------------------------------------------------------------------------------------------------    
public:
    SymbolInstructionWrite();

    virtual ~SymbolInstructionWrite();

    virtual string toString() const;

    void execute(map<string, StructVar *> &dicoVariables);

    static Symbol *analyse(string &stringToAnalyse, string &stringSymbolDetected);

    virtual void affectExpression(SymbolExpression *expression);

    Symbol *optimize(map<string, StructVar *> &dicoVariables);

    virtual void check(map<string, StructVar *> &dicoVariables);

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /** The expression to write. */
    SymbolExpression *symbolExpression;
};

#endif
