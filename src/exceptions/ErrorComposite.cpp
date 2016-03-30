#include <list>
#include <sstream>
#include <iostream>
#include "ErrorComposite.h"

using namespace std;

ErrorComposite::ErrorComposite() throw() : Error(ERROR_COMPOSITE, WARNING) {
}

ErrorComposite::~ErrorComposite() throw() {
    for (Error *error : components) {
        delete error;
    }
}

ErrorComposite::ErrorComposite(list<Error *> *ptListErrors) throw()
        : Error(ERROR_COMPOSITE, WARNING) {
    if (ptListErrors != NULL) {
        for (list<Error *>::iterator it = ptListErrors->begin(); it != ptListErrors->end(); it++) {
            addError(*it);
        }
        delete ptListErrors;
    }
}

void ErrorComposite::addError(Error *error) {
    components.push_back(error);
    if (error->getLevel() > level) {
        level = error->getLevel();
    }
}

string ErrorComposite::toStringDetails() const throw() {
    stringstream s;
    int iErrorMax = components.size() - 1;
    int i = 0;

    for (list<Error *>::const_iterator it = components.begin(); it != components.end(); it++, i++) {
        s << (*it)->toString();
        if (i != iErrorMax) {
            s << endl;
        }
    }

    return s.str();
}

string ErrorComposite::toString() const throw() {
    return toStringDetails();
}
