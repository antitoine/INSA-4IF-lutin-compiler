#ifndef LUT_ERRORCOMPOSITE_H
#define LUT_ERRORCOMPOSITE_H

#include <list>
#include "Error.h"

using namespace std;

class ErrorComposite : public Error {
public:
    ErrorComposite() throw();
    ErrorComposite(list<Error*> *ptListErrors) throw();
    virtual ~ErrorComposite() throw();
    void addError(Error * error);

    virtual string toString() const throw();

protected:
    list<Error *> components;

    virtual string toStringDetails() const throw();
};


#endif //LUT_ERRORCOMPOSITE_H
