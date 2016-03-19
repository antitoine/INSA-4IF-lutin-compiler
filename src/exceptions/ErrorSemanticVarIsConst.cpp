#include <sstream>
#include "ErrorSemanticVarIsConst.h"

using namespace std;

ErrorSemanticVarIsConst::~ErrorSemanticVarIsConst() throw() {

}

ErrorSemanticVarIsConst::ErrorSemanticVarIsConst(string varName) throw()
        : ErrorSemantic(ERROR_SEMANTIC_VAR_IS_CONST, WARNING), varName(varName) {
}

string ErrorSemanticVarIsConst::whatDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << varName << "\" is a constant and can't be modified.";
    return s.str();
}
