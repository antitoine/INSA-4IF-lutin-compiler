#ifndef LUT_ERRORSEMANTICVARNOTUSED_H
#define LUT_ERRORSEMANTICVARNOTUSED_H

#include <string>
#include "ErrorSemantic.h"

using namespace std;

class ErrorSemanticVarNotUsed : public ErrorSemantic {
public:
    ErrorSemanticVarNotUsed(const string & varName, bool notInitialized = false) throw();
    virtual ~ErrorSemanticVarNotUsed() throw();

protected:
    string varName;
    bool isNotInitialized;
    virtual string toStringDetails() const throw();
};

#endif //LUT_ERRORSEMANTICVARNOTUSED_H
