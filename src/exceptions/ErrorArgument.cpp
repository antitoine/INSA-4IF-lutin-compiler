#include <string>
#include "ErrorArgument.h"

using namespace std;

ErrorArgument::ErrorArgument() throw() {
}

ErrorArgument::~ErrorArgument() throw() {
}

string ErrorArgument::toString() const throw() {
    return "Error: unable to get the file path argument";
}
