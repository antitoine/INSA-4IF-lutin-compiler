#include "ErrorLexical.h"

ErrorLexical::~ErrorLexical() throw() {

}

ErrorLexical::ErrorLexical(int number, int level) throw()
        : Error(number, level) {

}
