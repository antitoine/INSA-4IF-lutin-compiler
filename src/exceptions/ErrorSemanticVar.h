#ifndef LUT_ERRORSEMANTICVAR_H
#define LUT_ERRORSEMANTICVAR_H

#include "ErrorSemantic.h"
#include "../symbols/SymbolVariable.h"

class ErrorSemanticVar : public ErrorSemantic {
public:
    ErrorSemanticVar(int number, int level, const string & varName, int lineError, int charError);
    virtual ~ErrorSemanticVar() throw();

protected:
    string varName;
    virtual string toStringDetails() const throw() = 0;
};


#endif //LUT_ERRORSEMANTICVAR_H
