#ifndef LUT_ERRORSEMANTICVARALREADYDECLARED_H
#define LUT_ERRORSEMANTICVARALREADYDECLARED_H

#include <string>
#include "ErrorSemanticVar.h"
#include "../symbols/SymbolVariable.h"

using namespace std;

class ErrorSemanticVarAlreadyDeclared : public ErrorSemanticVar {
public:
    ErrorSemanticVarAlreadyDeclared(SymbolVariable * variable, bool constant) throw();
    virtual ~ErrorSemanticVarAlreadyDeclared() throw();

protected:
    bool isConstant;
    virtual string toStringDetails() const throw();
};


#endif //LUT_ERRORSEMANTICVARALREADYDECLARED_H
