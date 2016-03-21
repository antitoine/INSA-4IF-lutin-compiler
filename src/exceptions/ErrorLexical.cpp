#include "ErrorLexical.h"

ErrorLexical::~ErrorLexical() throw() {

}

ErrorLexical::ErrorLexical(int number, int level, int numLineError, int numCharError) throw()
        : Error(number, level, numLineError, numCharError) {

}
