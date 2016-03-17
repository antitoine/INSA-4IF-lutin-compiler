#include <string>
#include <sstream>
#include "Error.h"
using namespace std;

Error::Error(int number, int level) throw()
        : number(number), level(level) {

}

Error::~Error() throw() {

}

string Error::what(int line, int charPos) const throw() {
    stringstream s;

    if (level == WARNING) {
        s << "WARNING ";
    } else if (level == CRITICAL_ERROR) {
        s << "ERROR ";
    }

    s << "at line " << line << ", character " << charPos << ": ";

    s << whatDetails();

    return s.str();
}

int Error::getLevel() const throw() {
    return level;
}

