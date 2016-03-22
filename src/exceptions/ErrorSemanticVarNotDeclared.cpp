#include <sstream>
#include "ErrorSemanticVarNotDeclared.h"

using namespace std;

ErrorSemanticVarNotDeclared::~ErrorSemanticVarNotDeclared() throw() {

}

ErrorSemanticVarNotDeclared::ErrorSemanticVarNotDeclared(const string & varName, int lineError, int charError) throw()
        : ErrorSemanticVar(ERROR_SEMANTIC_VAR_NOT_DECLARED, WARNING, varName, lineError, charError) {
}

string ErrorSemanticVarNotDeclared::toStringDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << varName << "\" is used but not declared.";
    return s.str();
}
