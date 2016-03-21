#include <string>
#include <sstream>
#include "ErrorLexicalUnexpectedSymbol.h"

using namespace std;

ErrorLexicalUnexpectedSymbol::ErrorLexicalUnexpectedSymbol(const string & symbolName, int numLine, int numChar)
        : ErrorLexical(ERROR_LEXICAL_UNEXPECTED_SYMBOL, CRITICAL_ERROR, numLine, numChar), symbolName(symbolName) {
}

ErrorLexicalUnexpectedSymbol::ErrorLexicalUnexpectedSymbol(const string & symbolName, Symbol* expectedSymbol, int numLine, int numChar)
        : ErrorLexical(ERROR_LEXICAL_UNEXPECTED_SYMBOL, WARNING, numLine, numChar), symbolName(symbolName),
          expectedSymbol(expectedSymbol) {
}

ErrorLexicalUnexpectedSymbol::~ErrorLexicalUnexpectedSymbol() throw() {

}

string ErrorLexicalUnexpectedSymbol::toStringDetails() const throw() {
    stringstream s;
    if (this->getLevel() == WARNING) {
        s << "Unexpected symbol read and ignored (\"" << symbolName << "\").";
    } else {
        s << "Unexpected symbol read and caused program failure (\"" << symbolName << "\").";
    }
    return s.str();
}

Symbol* ErrorLexicalUnexpectedSymbol::getExpectedSymbol() const {
    return expectedSymbol;
}
