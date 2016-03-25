#ifndef LUT_ERRORSEMANTICINCORRECTNUMERICVALUE_H
#define LUT_ERRORSEMANTICINCORRECTNUMERICVALUE_H

#include "ErrorSemantic.h"
#include "../symbols/SymbolInstructionRead.h"

class ErrorSemanticIncorrectNumericValue : public ErrorSemantic {
public:
    ErrorSemanticIncorrectNumericValue(SymbolInstructionRead * instructionRead) throw();
    virtual ~ErrorSemanticIncorrectNumericValue() throw();

protected:
    SymbolInstructionRead * instructionRead;
    virtual string toStringDetails() const throw();
};

#endif //LUT_ERRORSEMANTICINCORRECTNUMERICVALUE_H
