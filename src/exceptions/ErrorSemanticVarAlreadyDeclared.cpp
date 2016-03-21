#include <sstream>
#include "ErrorSemanticVarAlreadyDeclared.h"

ErrorSemanticVarAlreadyDeclared::~ErrorSemanticVarAlreadyDeclared() throw() {

}

ErrorSemanticVarAlreadyDeclared::ErrorSemanticVarAlreadyDeclared(SymbolVariable * variable, bool constant) throw()
        : ErrorSemanticVar(ERROR_SEMANTIC_VAR_ALREADY_DECLARED, WARNING, variable), isConstant(constant) {
}

string ErrorSemanticVarAlreadyDeclared::toStringDetails() const throw() {
    stringstream s;
    s << "The ";
    if (isConstant) {
        s << "constant ";
    } else {
        s << "variable ";
    }
    s << "\"" << variable->getName() << "\" has already been declared.";
    return s.str();
}