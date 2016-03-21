#ifndef LUT_ERRORSEMANTICVAR_H
#define LUT_ERRORSEMANTICVAR_H

#include "ErrorSemantic.h"
#include "../symbols/SymbolVariable.h"

class ErrorSemanticVar : public ErrorSemantic {
public:
    ErrorSemanticVar(int number, int level, SymbolVariable * variable);
    virtual ~ErrorSemanticVar() throw();

protected:
    SymbolVariable * variable;
    virtual string toStringDetails() const throw() = 0;
};


#endif //LUT_ERRORSEMANTICVAR_H
