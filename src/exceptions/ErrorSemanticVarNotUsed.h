#ifndef LUT_ERRORSEMANTICVARNOTUSED_H
#define LUT_ERRORSEMANTICVARNOTUSED_H

#include <string>
#include "ErrorSemantic.h"

using namespace std;

class ErrorSemanticVarNotUsed : public ErrorSemantic {
public:
    ErrorSemanticVarNotUsed(string varName) throw();
    virtual ~ErrorSemanticVarNotUsed() throw();

protected:
    string varName;
    virtual string whatDetails() const throw();
};

#endif //LUT_ERRORSEMANTICVARNOTUSED_H
