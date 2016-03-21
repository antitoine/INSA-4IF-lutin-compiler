#ifndef LUT_ERRORLEXICAL_H
#define LUT_ERRORLEXICAL_H

#include "Error.h"

class ErrorLexical : public Error {
public:
    ErrorLexical(int number, int level=WARNING, int numLineError=-1, int numCharError=-1) throw();
    virtual ~ErrorLexical() throw();
};


#endif //LUT_ERRORLEXICAL_H
