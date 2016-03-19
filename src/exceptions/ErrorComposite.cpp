#include <list>
#include "ErrorComposite.h"

using namespace std;

ErrorComposite::ErrorComposite() : Error(ERROR_COMPOSITE, WARNING) {

}

ErrorComposite::ErrorComposite(std::list < Error * > *errors)
        : Error(ERROR_COMPOSITE, WARNING) {
    for (Error * e : *errors) {
        addError(e);
    }
}


ErrorComposite::~ErrorComposite() {
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

