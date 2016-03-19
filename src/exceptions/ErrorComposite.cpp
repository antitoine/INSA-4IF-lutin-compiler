#include <list>
#include "ErrorComposite.h"

using namespace std;

ErrorComposite::ErrorComposite() throw() : Error(ERROR_COMPOSITE, WARNING) {

}

ErrorComposite::ErrorComposite(std::list < Error * > *errors) throw()
        : Error(ERROR_COMPOSITE, WARNING) {
    for (Error * e : *errors) {
        addError(e);
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

