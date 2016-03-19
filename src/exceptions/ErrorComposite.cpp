#include <list>
#include <sstream>
#include <iostream>
#include "ErrorComposite.h"

using namespace std;

ErrorComposite::ErrorComposite() throw() : Error(ERROR_COMPOSITE, WARNING) {

}

ErrorComposite::ErrorComposite(std::list < Error * > *ptListErrors) throw()
        : Error(ERROR_COMPOSITE, WARNING) {
    if (ptListErrors != NULL) {
        for (std::list<Error*>::iterator it = ptListErrors->begin(); it != ptListErrors->end(); it++) {
            addError(*it);
        }
        delete ptListErrors;
    }
}


ErrorComposite::~ErrorComposite() throw() {
    for (Error * error : components) {
        delete error;
    }
}

void ErrorComposite::addError(Error *error) {
    components.push_back(error);
    if (error->getLevel() > level) {
        level = error->getLevel();
    }
}

string ErrorComposite::whatDetails() const throw() {
    stringstream s;
    int iErrorMax = components.size() - 1;
    int i = 0;

    for (list<Error*>::const_iterator it = components.begin(); it != components.end(); it++, i++) {
        s << (*it)->whatDefault();
        if (i != iErrorMax) {
            s << endl;
        }
    }

    return s.str();
}

string ErrorComposite::what(int line, int charPos) const throw() {
    return whatDetails();
}
