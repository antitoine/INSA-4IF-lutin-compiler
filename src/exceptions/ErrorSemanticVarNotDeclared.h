#ifndef LUT_ERRORSEMANTICVARNOTDECLARED_H
#define LUT_ERRORSEMANTICVARNOTDECLARED_H

#include <string>
#include "ErrorSemanticVar.h"

using namespace std;

class ErrorSemanticVarNotDeclared : public ErrorSemanticVar {
public:
    ErrorSemanticVarNotDeclared(SymbolVariable * variable) throw();
    virtual ~ErrorSemanticVarNotDeclared() throw();

protected:
    virtual string toStringDetails() const throw();
};


#endif //LUT_ERRORSEMANTICVARNOTDECLARED_H
