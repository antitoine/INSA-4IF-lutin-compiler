#include <sstream>
#include "ErrorSemanticVarNotDeclared.h"

using namespace std;

ErrorSemanticVarNotDeclared::~ErrorSemanticVarNotDeclared() throw() {

}

ErrorSemanticVarNotDeclared::ErrorSemanticVarNotDeclared(string varName)
        : varName(varName), ErrorSemantic(ERROR_SEMANTIC_VAR_NOT_DECLARED, CRITICAL_ERROR) {
}

string ErrorSemanticVarNotDeclared::whatDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << varName << "\" is not declared.";
    return s.str();
}
