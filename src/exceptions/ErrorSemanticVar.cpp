#include <sstream>
#include "ErrorSemanticVar.h"

ErrorSemanticVar::~ErrorSemanticVar() throw() {

}

ErrorSemanticVar::ErrorSemanticVar(int number, int level, const string & varName, int lineError, int charError)
        : ErrorSemantic(number, level, lineError, charError), varName(varName) {
}