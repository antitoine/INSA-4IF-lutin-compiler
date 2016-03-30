#include <string>
#include <sstream>
#include "Error.h"

using namespace std;

Error::Error(int number, int level, int numLineError, int numCharError) throw()
        : number(number), level(level), numLineError(numLineError), numCharError(numCharError) {
}

Error::~Error() throw() {
}

int Error::getLevel() const throw() {
    return level;
}

int Error::getNumber() const throw() {
    return number;
}

string Error::toString() const throw() {
    return toString(numLineError, numCharError);
}

string Error::toString(int linePos, int charPos) const throw() {
    stringstream s;

    if (level == WARNING) {
        s << "WARNING ";
    } else if (level == ERROR) {
        s << "ERROR ";
    }

    if (linePos != -1) {
        s << "at line " << numLineError;
    }
    if (charPos != -1) {
        s << ", character " << numCharError;
    }
    s << ": ";

    s << toStringDetails();

    return s.str();
}

const char *Error::what() const throw() {
    return toString().c_str();
}
