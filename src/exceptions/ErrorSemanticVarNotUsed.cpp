#include <sstream>
#include "ErrorSemanticVarNotUsed.h"

using namespace std;

ErrorSemanticVarNotUsed::~ErrorSemanticVarNotUsed() throw() {

}

ErrorSemanticVarNotUsed::ErrorSemanticVarNotUsed(const string &varName, bool notInitialized) throw()
        : ErrorSemantic(ERROR_SEMANTIC_VAR_NOT_USED, WARNING), varName(varName), isNotInitialized(notInitialized) {
}

string ErrorSemanticVarNotUsed::toStringDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << varName << "\" is never ";
    if (isNotInitialized) {
        s << "affected and ";
    }
    s << "used.";
    return s.str();
}
