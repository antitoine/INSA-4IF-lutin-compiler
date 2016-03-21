#include <sstream>
#include "ErrorSemanticVarNotInitialized.h"

using namespace std;

ErrorSemanticVarNotInitialized::~ErrorSemanticVarNotInitialized() throw() {

}

ErrorSemanticVarNotInitialized::ErrorSemanticVarNotInitialized(SymbolVariable * variable) throw()
        : ErrorSemanticVar(ERROR_SEMANTIC_VAR_NOT_INITIALIZED, WARNING, variable) {
}

string ErrorSemanticVarNotInitialized::toStringDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << variable->getName() << "\" is used but not initialized.";
    return s.str();
}
