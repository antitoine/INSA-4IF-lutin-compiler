#ifndef LUT_ERRORSEMANTICVARNOTUSED_H
#define LUT_ERRORSEMANTICVARNOTUSED_H

#include <string>
#include "ErrorSemantic.h"

using namespace std;

/**
 * Warning: a variable is not used.
 */
class ErrorSemanticVarNotUsed : public ErrorSemantic {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    ErrorSemanticVarNotUsed(const string &varName, bool notInitialized = false) throw();

    virtual ~ErrorSemanticVarNotUsed() throw();

protected:
    virtual string toStringDetails() const throw();

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /** Variable's name. */
    string varName;

    /** True if the variable is initialized. */
    bool isNotInitialized;
};

#endif //LUT_ERRORSEMANTICVARNOTUSED_H
