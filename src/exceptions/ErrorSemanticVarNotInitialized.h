#ifndef LUT_ERRORSEMANTICVARNOTINITIALIZED_H
#define LUT_ERRORSEMANTICVARNOTINITIALIZED_H

#include <string>
#include "../symbols/SymbolVariable.h"
#include "ErrorSemanticVar.h"

using namespace std;

/**
 * Error: try to use an uninitialized variable.
 */
class ErrorSemanticVarNotInitialized : public ErrorSemanticVar {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    ErrorSemanticVarNotInitialized(const string &varName, int lineError, int charError) throw();

    virtual ~ErrorSemanticVarNotInitialized() throw();

protected:
    virtual string toStringDetails() const throw();
};


#endif //LUT_ERRORSEMANTICVARNOTINITIALIZED_H
