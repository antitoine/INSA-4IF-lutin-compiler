#ifndef LUT_ERRORCOMPOSITE_H
#define LUT_ERRORCOMPOSITE_H

#include <list>
#include "Error.h"

using namespace std;

class ErrorComposite : public Error {
public:
    ErrorComposite() throw();
    ErrorComposite(list<Error*> * errors) throw();
    virtual ~ErrorComposite() throw();
    void addError(Error * error);

private:
    list<Error *> components;
};


#endif //LUT_ERRORCOMPOSITE_H
