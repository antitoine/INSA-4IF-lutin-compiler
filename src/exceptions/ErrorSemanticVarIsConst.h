#ifndef LUT_ERRORSEMANTICVARISCONST_H
#define LUT_ERRORSEMANTICVARISCONST_H

#include <string>
#include "ErrorSemantic.h"

using namespace std;

class ErrorSemanticVarIsConst : public ErrorSemantic {
public:
    ErrorSemanticVarIsConst(string varName) throw();
    virtual ~ErrorSemanticVarIsConst() throw();

protected:
    string varName;
    virtual string whatDetails() const throw();
};


#endif //LUT_ERRORSEMANTICVARISCONST_H
