#include <sstream>
#include "ErrorSemanticVarNotInitialized.h"

using namespace std;

ErrorSemanticVarNotInitialized::~ErrorSemanticVarNotInitialized() throw() {

}

ErrorSemanticVarNotInitialized::ErrorSemanticVarNotInitialized(string varName)
        : varName(varName), ErrorSemantic(ERROR_SEMANTIC_VAR_NOT_DECLARED, CRITICAL_ERROR) {
}

string ErrorSemanticVarNotInitialized::whatDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << varName << "\" is not initialized.";
    return s.str();
}
