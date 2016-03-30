#include <sstream>
#include "ErrorSemanticDivisionZero.h"

using namespace std;

ErrorSemanticDivisionZero::ErrorSemanticDivisionZero(int lineError, int charError) throw()
        : ErrorSemantic(ERROR_SEMANTIC_DIVISION_ZERO, ERROR, lineError, charError) {
}

ErrorSemanticDivisionZero::~ErrorSemanticDivisionZero() throw() {
}

string ErrorSemanticDivisionZero::toStringDetails() const throw() {
    stringstream s;
    s << "Division by zero is forbidden.";
    return s.str();
}