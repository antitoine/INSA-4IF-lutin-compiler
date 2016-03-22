#include <sstream>
#include "ErrorSemanticVarAlreadyDeclared.h"

ErrorSemanticVarAlreadyDeclared::~ErrorSemanticVarAlreadyDeclared() throw() {

}

ErrorSemanticVarAlreadyDeclared::ErrorSemanticVarAlreadyDeclared(const string & varName, bool constant, int lineError, int charError) throw()
        : ErrorSemanticVar(ERROR_SEMANTIC_VAR_ALREADY_DECLARED, WARNING, varName, lineError, charError), isConstant(constant) {
}

string ErrorSemanticVarAlreadyDeclared::toStringDetails() const throw() {
    stringstream s;
    s << "The ";
    if (isConstant) {
        s << "constant ";
    } else {
        s << "variable ";
    }
    s << "\"" << varName << "\" has already been declared.";
    return s.str();
}