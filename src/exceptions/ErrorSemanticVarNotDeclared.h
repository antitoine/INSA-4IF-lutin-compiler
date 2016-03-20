#ifndef LUT_ERRORSEMANTICVARNOTDECLARED_H
#define LUT_ERRORSEMANTICVARNOTDECLARED_H

#include <string>
#include "ErrorSemantic.h"

using namespace std;

class ErrorSemanticVarNotDeclared : public ErrorSemantic {
public:
    ErrorSemanticVarNotDeclared(string varName) throw();
    virtual ~ErrorSemanticVarNotDeclared() throw();

protected:
    string varName;
    virtual string whatDetails() const throw();
};


#endif //LUT_ERRORSEMANTICVARNOTDECLARED_H
