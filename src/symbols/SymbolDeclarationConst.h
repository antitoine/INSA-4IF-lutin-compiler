#if !defined ( SYMBOLDECLARATIONCONST )
#define SYMBOLDECLARATIONCONST

#include "SymbolDeclaration.h"
#include "SymbolVariable.h"

using namespace std;

/**
 * Comparator used by the map of constants, since the key is a pointer.
 * Sort by the name of the variables.
 */
struct comparatorBySymbolVariablePt {
    bool operator()(const SymbolVariable *a, const SymbolVariable *b) const {
        return a->getName() < b->getName();
    }
};

/**
 * Class representing the declaration of a constant.
 */
class SymbolDeclarationConst : public SymbolDeclaration {
// METHODS ------------------------------------------------------------------------------------------------------------- 
public:
    SymbolDeclarationConst();

    virtual ~SymbolDeclarationConst();

    virtual string toString() const;

    void execute(map<string, StructVar *> &dicoVariables);

    virtual void check(map<string, StructVar *> &dicoVariables);

    /**
     * Erase the constants of the current SymbolDeclarationConst in the map passed by parameter.
     * @param dicoVariables The map with the variables' status used by the program.
     */
    void detachConstant(map<string, StructVar *> &dicoVariables);

    /**
     * Check if the SymbolDeclarationConst can be detected in stringToAnalyse.
     * @param stringToAnalyse String consumed if the symbol have been detected.
     * @param stringSymbolDetected String description of the symbol.
     * @return The pointer of the symbol if detected, NULL otherwise.
     */
    static Symbol *analyse(string &stringToAnalyse, string &stringSymbolDetected);

    /**
     * Add a constant to the current SymbolDeclarationConst.
     */
    void addConstant(SymbolVariable *pVariable);

    /**
     * Associate the value passed by parameter to the last constant added to the current SymbolDeclarationConst. Add
     * the constant to the map of variables.
     * @param dicoVariables The map with the variables' status used by the program.
     */
    void addConstantValue(float constantValue, map<string, StructVar *> &dicoVariables);

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
private:
    /**
     * Map with all the constants managed by the current symbol.
     * @Key : Pointer to the variable
     * @Value : The initialization value
     * @Comparator : The custom comparator, on the name of the SymbolVariable objects.
     */
    map<SymbolVariable *, float, comparatorBySymbolVariablePt> constants;

    /**
     * Temporary SymbolVariable.
     */
    SymbolVariable *temporaryPtVariable;
};

#endif
