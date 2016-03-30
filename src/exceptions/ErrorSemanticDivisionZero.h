#ifndef LUT_ERRORSEMANTICDIVISIONZERO_H
#define LUT_ERRORSEMANTICDIVISIONZERO_H

#include "ErrorSemantic.h"

using namespace std;

/**
 * Error: division by zero.
 */
class ErrorSemanticDivisionZero : public ErrorSemantic {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    ErrorSemanticDivisionZero(int lineError, int charError) throw();

    virtual ~ErrorSemanticDivisionZero() throw();

protected:
    virtual string toStringDetails() const throw();
};



#endif //LUT_ERRORSEMANTICDIVISIONZERO_H
