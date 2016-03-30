#ifndef LUT_ERRORCOMPOSITE_H
#define LUT_ERRORCOMPOSITE_H

#include <list>
#include "Error.h"

using namespace std;

/**
 * Composite of errors.
 */
class ErrorComposite : public Error {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    ErrorComposite() throw();

    ErrorComposite(list<Error *> *ptListErrors) throw();

    virtual ~ErrorComposite() throw();

    virtual string toString() const throw();

    /**
     * Add a new error to the current composite.
     * @error Error to add.
     */
    void addError(Error *error);

protected:
    virtual string toStringDetails() const throw();

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /** List of error components. */
    list<Error *> components;
};

#endif //LUT_ERRORCOMPOSITE_H
