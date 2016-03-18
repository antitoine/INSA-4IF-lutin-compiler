#include <sstream>
#include "ErrorSemanticVarAlreadyDeclared.h"

ErrorSemanticVarAlreadyDeclared::~ErrorSemanticVarAlreadyDeclared() throw() {

}

ErrorSemanticVarAlreadyDeclared::ErrorSemanticVarAlreadyDeclared(string duplicateVarName, bool constant)
        : varName(duplicateVarName), isConstant(constant), ErrorSemantic(ERROR_SEMANTIC_VAR_ALREADY_DECLARED, WARNING) {
}

string ErrorSemanticVarAlreadyDeclared::whatDetails() const throw() {
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