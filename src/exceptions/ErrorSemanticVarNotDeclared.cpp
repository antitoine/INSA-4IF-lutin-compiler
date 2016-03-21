#include <sstream>
#include "ErrorSemanticVarNotDeclared.h"

using namespace std;

ErrorSemanticVarNotDeclared::~ErrorSemanticVarNotDeclared() throw() {

}

ErrorSemanticVarNotDeclared::ErrorSemanticVarNotDeclared(SymbolVariable * variable) throw()
        : ErrorSemanticVar(ERROR_SEMANTIC_VAR_NOT_DECLARED, WARNING, variable) {
}

string ErrorSemanticVarNotDeclared::toStringDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << variable->getName() << "\" is used but not declared.";
    return s.str();
}
