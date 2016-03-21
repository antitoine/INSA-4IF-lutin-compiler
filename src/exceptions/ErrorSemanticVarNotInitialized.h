#ifndef LUT_ERRORSEMANTICVARNOTINITIALIZED_H
#define LUT_ERRORSEMANTICVARNOTINITIALIZED_H

#include <string>
#include "../symbols/SymbolVariable.h"
#include "ErrorSemanticVar.h"

using namespace std;

class ErrorSemanticVarNotInitialized : public ErrorSemanticVar {
public:
    ErrorSemanticVarNotInitialized(SymbolVariable * variable) throw();
    virtual ~ErrorSemanticVarNotInitialized() throw();

protected:
    virtual string toStringDetails() const throw();
};


#endif //LUT_ERRORSEMANTICVARNOTINITIALIZED_H
