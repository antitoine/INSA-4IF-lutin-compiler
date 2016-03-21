#include <sstream>
#include "ErrorSemanticVarIsConst.h"

using namespace std;

ErrorSemanticVarIsConst::~ErrorSemanticVarIsConst() throw() {

}

ErrorSemanticVarIsConst::ErrorSemanticVarIsConst(SymbolVariable * variable) throw()
        : ErrorSemanticVar(ERROR_SEMANTIC_VAR_IS_CONST, WARNING, variable) {
}

string ErrorSemanticVarIsConst::toStringDetails() const throw() {
    stringstream s;
    s << "The variable " << "\"" << variable->getName() << "\" is a constant and can't be modified.";
    return s.str();
}
