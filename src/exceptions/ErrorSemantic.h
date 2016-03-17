#ifndef LUT_ERRORSEMANTIC_H
#define LUT_ERRORSEMANTIC_H

#include "Error.h"

class ErrorSemantic : public Error {
public:
    ErrorSemantic(int number, int level=CRITICAL_ERROR) throw();
    virtual ~ErrorSemantic() throw();
};


#endif //LUT_ERRORSEMANTIC_H
