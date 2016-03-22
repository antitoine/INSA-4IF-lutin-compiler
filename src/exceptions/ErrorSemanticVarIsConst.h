#ifndef LUT_ERRORSEMANTICVARISCONST_H
#define LUT_ERRORSEMANTICVARISCONST_H

#include <string>
#include "ErrorSemanticVar.h"

using namespace std;

class ErrorSemanticVarIsConst : public ErrorSemanticVar {
public:
    ErrorSemanticVarIsConst(const string & varName, int lineError, int charError) throw();
    virtual ~ErrorSemanticVarIsConst() throw();

protected:
    virtual string toStringDetails() const throw();
};


#endif //LUT_ERRORSEMANTICVARISCONST_H
