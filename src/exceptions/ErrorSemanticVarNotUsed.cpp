#include <sstream>
#include "ErrorSemanticVarNotUsed.h"

using namespace std;

ErrorSemanticVarNotUsed::~ErrorSemanticVarNotUsed() throw() {

}

ErrorSemanticVarNotUsed::ErrorSemanticVarNotUsed(string varName) throw()
        : varName(varName), ErrorSemantic(ERROR_SEMANTIC_VAR_NOT_USED, WARNING) {
}

string ErrorSemanticVarNotUsed::whatDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << varName << "\" is never used.";
    return s.str();
}
