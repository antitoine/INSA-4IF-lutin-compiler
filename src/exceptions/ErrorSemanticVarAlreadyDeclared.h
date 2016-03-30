#ifndef LUT_ERRORSEMANTICVARALREADYDECLARED_H
#define LUT_ERRORSEMANTICVARALREADYDECLARED_H

#include <string>
#include "ErrorSemanticVar.h"
#include "../symbols/SymbolVariable.h"

using namespace std;

/**
 * Error: a variable is declared twice.
 */
class ErrorSemanticVarAlreadyDeclared : public ErrorSemanticVar {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    ErrorSemanticVarAlreadyDeclared(const string &varName, bool constant, int lineError, int charError) throw();

    virtual ~ErrorSemanticVarAlreadyDeclared() throw();

protected:
    virtual string toStringDetails() const throw();

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /** True if the variable is a constant. */
    bool isConstant;
};


#endif //LUT_ERRORSEMANTICVARALREADYDECLARED_H
