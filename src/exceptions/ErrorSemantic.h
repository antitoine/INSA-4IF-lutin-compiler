#ifndef LUT_ERRORSEMANTIC_H
#define LUT_ERRORSEMANTIC_H

#include "Error.h"

class ErrorSemantic : public Error {
public:
    ErrorSemantic(int number, int level=ERROR, int numLineError=-1, int numCharError=-1) throw();
    virtual ~ErrorSemantic() throw();
};


#endif //LUT_ERRORSEMANTIC_H
