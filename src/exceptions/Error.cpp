#include <string>
#include <sstream>
#include "Error.h"
using namespace std;

Error::Error(int number, int level) throw()
        : number(number), level(level) {

}

Error::~Error() throw() {

}

const char* Error::what() const throw() {
    return what(-1, -1).c_str();
}

string Error::what(int line, int charPos) const throw() {
    stringstream s;

    if (level == WARNING) {
        s << "WARNING ";
    } else if (level == CRITICAL_ERROR) {
        s << "ERROR ";
    }

    if (line != -1) {
        s << "at line " << line;
    }
    if (charPos != -1) {
        s << ", character " << charPos;
    }
    s << ": ";

    s << whatDetails();

    return s.str();
}

int Error::getLevel() const throw() {
    return level;
}

int Error::getNumber() const throw() {
    return number;
}
