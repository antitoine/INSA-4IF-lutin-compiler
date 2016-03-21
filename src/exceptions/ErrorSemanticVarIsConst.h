#ifndef LUT_ERRORSEMANTICVARISCONST_H
#define LUT_ERRORSEMANTICVARISCONST_H

#include <string>
#include "ErrorSemanticVar.h"

using namespace std;

class ErrorSemanticVarIsConst : public ErrorSemanticVar {
public:
    ErrorSemanticVarIsConst(SymbolVariable * variable) throw();
    virtual ~ErrorSemanticVarIsConst() throw();

protected:
    virtual string toStringDetails() const throw();
};


#endif //LUT_ERRORSEMANTICVARISCONST_H
