#include <sstream>
#include "ErrorLexicalMissingSymbol.h"

ErrorLexicalMissingSymbol::ErrorLexicalMissingSymbol(int numLine, int numChar, Symbol * missingSymbol) throw()
        : ErrorLexical(ERROR_LEXICAL_MISSING_SYMBOL, WARNING, numLine, numChar), missingSymbol(missingSymbol) {
}

ErrorLexicalMissingSymbol::~ErrorLexicalMissingSymbol() throw() {

}

string ErrorLexicalMissingSymbol::toStringDetails() const throw() {
    stringstream s;
    s << "Missing symbol detected (\"" << missingSymbol->toString() << "\") and inserted.";
    return s.str();
}

Symbol* ErrorLexicalMissingSymbol::getMissingSymbol() const {
    return missingSymbol;
}