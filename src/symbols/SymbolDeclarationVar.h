#if ! defined ( SYMBOLDECLARATIONVAR )
#define SYMBOLDECLARATIONVAR

#include "SymbolDeclaration.h"
#include "SymbolVariable.h"

/**
 * Class representing the declaration of a simple variable.
 */
class SymbolDeclarationVar : public SymbolDeclaration
{
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolDeclarationVar();
    virtual ~SymbolDeclarationVar();

    virtual string toString() const;

    void execute(map<string, StructVar*>& dicoVariables);

    /**
     * Check if the SymbolDeclarationConst can be detected in stringToAnalyse.
     * @param stringToAnalyse String consumed if the symbol have been detected.
     * @param stringSymbolDetected String description of the symbol.
     * @return The pointer of the symbol if detected, NULL otherwise.
     */
    static Symbol * analyse(string & stringToAnalyse, string & stringSymbolDetected);

    /**
     * Add a variable to the list of variables managed by the current SymbolDeclarationVar.
     * @param dicoVariables The map with the variables' status used by the program.
     */
    void addVariable(SymbolVariable *pVariable, map<string, StructVar*>& dicoVariables);

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
private:
    /**
     * List of variables managed by the declaration symbol.
     */
    list<SymbolVariable*> variables;
};

#endif
