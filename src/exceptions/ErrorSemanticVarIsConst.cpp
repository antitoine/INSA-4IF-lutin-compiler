#include <sstream>
#include "ErrorSemanticVarIsConst.h"

using namespace std;

ErrorSemanticVarIsConst::~ErrorSemanticVarIsConst() throw() {

}

ErrorSemanticVarIsConst::ErrorSemanticVarIsConst(const string & varName, int lineError, int charError) throw()
        : ErrorSemanticVar(ERROR_SEMANTIC_VAR_IS_CONST, ERROR, varName, lineError, charError) {
}

string ErrorSemanticVarIsConst::toStringDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << varName << "\" is a constant and can't be modified.";
    return s.str();
}
