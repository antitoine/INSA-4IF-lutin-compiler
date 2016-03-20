#ifndef LUT_ERRORSEMANTICVARNOTINITIALIZED_H
#define LUT_ERRORSEMANTICVARNOTINITIALIZED_H

#include <string>
#include "ErrorSemantic.h"

using namespace std;

class ErrorSemanticVarNotInitialized : public ErrorSemantic {
public:
    ErrorSemanticVarNotInitialized(string varName) throw();
    virtual ~ErrorSemanticVarNotInitialized() throw();

protected:
    string varName;
    virtual string whatDetails() const throw();
};


#endif //LUT_ERRORSEMANTICVARNOTINITIALIZED_H
