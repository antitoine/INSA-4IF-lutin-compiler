#include <sstream>
#include "ErrorSemanticVar.h"

ErrorSemanticVar::~ErrorSemanticVar() throw() {

}

ErrorSemanticVar::ErrorSemanticVar(int number, int level, SymbolVariable * variable)
        : ErrorSemantic(number, level, variable->getNumLineDetection(), variable->getNumCharDetection()), variable(variable) {
}