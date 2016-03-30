#include "ErrorLexical.h"

ErrorLexical::ErrorLexical(int number, int level, int numLineError, int numCharError) throw()
        : Error(number, level, numLineError, numCharError) {
}

ErrorLexical::~ErrorLexical() throw() {
}

