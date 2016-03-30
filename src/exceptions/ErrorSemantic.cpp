#include "ErrorSemantic.h"

ErrorSemantic::~ErrorSemantic() throw() {
}

ErrorSemantic::ErrorSemantic(int number, int level, int numLineError, int numCharError) throw()
        : Error(number, level, numLineError, numCharError) {
}