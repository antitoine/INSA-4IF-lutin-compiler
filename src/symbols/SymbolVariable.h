#if !defined ( SYMBOLVARIABLE )
#define SYMBOLVARIABLE

#include "SymbolExpression.h"
#include "../StructVar.h"

using namespace std;

/**
 * Class representing a variable.
 */
class SymbolVariable : public SymbolExpression {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolVariable(string varName);

    virtual ~SymbolVariable();

    virtual string toString() const;

    static Symbol *analyse(string &stringToAnalyse, string &stringSymbolDetected);

    float eval(map<string, StructVar *> &dicoVariables);

    /**
     * Check the symbol, without the boolean value (false by default), for inheritance.
     */
    virtual void check(map<string, StructVar *> &dicoVariables);

    /**
     * Check the symbol, and check if the variable is a constant if checkConstantUpdate is true, ignore it otherwise.
     */
    virtual void check(map<string, StructVar *> &dicoVariables, bool checkConstantUpdate);

    virtual list<Error *> *checkEval(map<string, StructVar *> &dicoVariables);

    virtual SymbolExpression *optimizeExpression(map<string, StructVar *> &dicoVariables);

    /**
     * @return The name of the variable.
     */
    string getName() const;

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /** Variable's name. */
    string name;
};

#endif
