#ifndef LUT_ERRORSEMANTICINCORRECTNUMERICVALUE_H
#define LUT_ERRORSEMANTICINCORRECTNUMERICVALUE_H

#include "ErrorSemantic.h"
#include "../symbols/SymbolInstructionRead.h"

/**
 * Error: an incorrect numeric value have been read.
 */
class ErrorSemanticIncorrectNumericValue : public ErrorSemantic {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    ErrorSemanticIncorrectNumericValue(SymbolInstructionRead *instructionRead) throw();

    virtual ~ErrorSemanticIncorrectNumericValue() throw();

protected:
    virtual string toStringDetails() const throw();

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /** The read instruction that thrown the exception. */
    SymbolInstructionRead *instructionRead;
};

#endif //LUT_ERRORSEMANTICINCORRECTNUMERICVALUE_H
