#ifndef LUT_ERRORARGUMENT_H
#define LUT_ERRORARGUMENT_H

#include <exception>
#include <string>

using namespace std;

class ErrorArgument : public exception {
public:
    ErrorArgument() throw();
    virtual ~ErrorArgument() throw();
    virtual string toString() const throw();
};


#endif //LUT_ERRORARGUMENT_H
