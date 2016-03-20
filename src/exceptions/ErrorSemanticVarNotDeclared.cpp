#include <sstream>
#include "ErrorSemanticVarNotDeclared.h"

using namespace std;

ErrorSemanticVarNotDeclared::~ErrorSemanticVarNotDeclared() throw() {

}

ErrorSemanticVarNotDeclared::ErrorSemanticVarNotDeclared(string varName) throw()
        : varName(varName), ErrorSemantic(ERROR_SEMANTIC_VAR_NOT_DECLARED, WARNING) {
}

string ErrorSemanticVarNotDeclared::whatDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << varName << "\" is used but not declared.";
    return s.str();
}
