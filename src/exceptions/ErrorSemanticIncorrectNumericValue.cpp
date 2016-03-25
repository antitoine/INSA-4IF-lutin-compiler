#include <sstream>
#include <algorithm>
#include <string>
#include "ErrorSemanticIncorrectNumericValue.h"

using namespace std;

ErrorSemanticIncorrectNumericValue::~ErrorSemanticIncorrectNumericValue() throw() {

}

ErrorSemanticIncorrectNumericValue::ErrorSemanticIncorrectNumericValue(SymbolInstructionRead * instructionRead) throw()
        : ErrorSemantic(ERROR_SEMANTIC_INCORRECT_NUM_VALUE, ERROR), instructionRead(instructionRead) {
}

string ErrorSemanticIncorrectNumericValue::toStringDetails() const throw() {
    stringstream s;
    string read = instructionRead->toString();
    read.erase(std::remove(read.begin(), read.end(), '\n'), read.end());
    s << "Incorrect value read at instruction " << "\"" << read << "\".";
    return s.str();
}
