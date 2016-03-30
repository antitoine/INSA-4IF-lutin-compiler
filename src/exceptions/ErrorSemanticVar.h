#ifndef LUT_ERRORSEMANTICVAR_H
#define LUT_ERRORSEMANTICVAR_H

#include "ErrorSemantic.h"
#include "../symbols/SymbolVariable.h"

/**
 * Error on variable.
 */
class ErrorSemanticVar : public ErrorSemantic {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    ErrorSemanticVar(int number, int level, const string &varName, int lineError, int charError);

    virtual ~ErrorSemanticVar() throw();

protected:
    virtual string toStringDetails() const throw() = 0;

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /** Variable's name. */
    string varName;
};


#endif //LUT_ERRORSEMANTICVAR_H
