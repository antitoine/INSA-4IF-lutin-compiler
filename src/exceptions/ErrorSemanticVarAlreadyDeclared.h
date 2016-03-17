#ifndef LUT_ERRORSEMANTICVARALREADYDECLARED_H
#define LUT_ERRORSEMANTICVARALREADYDECLARED_H

#include <string>
#include "ErrorSemantic.h"

using namespace std;

class ErrorSemanticVarAlreadyDeclared : public ErrorSemantic {
public:
    ErrorSemanticVarAlreadyDeclared(string duplicateVarName, bool constant);
    virtual ~ErrorSemanticVarAlreadyDeclared() throw();

protected:
    string varName;
    bool isConstant;
    virtual string whatDetails() const throw();
};


#endif //LUT_ERRORSEMANTICVARALREADYDECLARED_H
