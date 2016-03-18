//
// Created by pierre on 18/03/16.
//

#include "ErrorComposite.h"

ErrorComposite::ErrorComposite() : Error(ERROR_COMPOSITE, WARNING) {

}

ErrorComposite::~ErrorComposite() {
    for (Error * error : components) {
        delete error;
    }
}

void ErrorComposite::addError(Error *error) {
    components.push_back(error);
}
