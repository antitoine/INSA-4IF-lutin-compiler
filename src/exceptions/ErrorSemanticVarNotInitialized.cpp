#include <sstream>
#include "ErrorSemanticVarNotInitialized.h"

using namespace std;

ErrorSemanticVarNotInitialized::~ErrorSemanticVarNotInitialized() throw() {

}

ErrorSemanticVarNotInitialized::ErrorSemanticVarNotInitialized(string varName) throw()
        : varName(varName), ErrorSemantic(ERROR_SEMANTIC_VAR_NOT_INITIALIZED, WARNING) {
}

string ErrorSemanticVarNotInitialized::whatDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << varName << "\" is used but not initialized.";
    return s.str();
}
