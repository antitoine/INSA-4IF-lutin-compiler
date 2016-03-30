#include <sstream>
#include "ErrorSemanticVarNotInitialized.h"

using namespace std;

ErrorSemanticVarNotInitialized::~ErrorSemanticVarNotInitialized() throw() {

}

ErrorSemanticVarNotInitialized::ErrorSemanticVarNotInitialized(const string &varName, int lineError,
                                                               int charError) throw()
        : ErrorSemanticVar(ERROR_SEMANTIC_VAR_NOT_INITIALIZED, ERROR, varName, lineError, charError) {
}

string ErrorSemanticVarNotInitialized::toStringDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << varName << "\" is used but not initialized.";
    return s.str();
}
