#include "ErrorSemantic.h"

ErrorSemantic::~ErrorSemantic() throw() {

}

ErrorSemantic::ErrorSemantic(int number, int level) throw()
        : Error(number, level) {

}