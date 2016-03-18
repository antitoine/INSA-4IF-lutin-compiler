#include <string>
#include <sstream>
#include "ErrorLexicalUnexpectedSymbol.h"

using namespace std;

ErrorLexicalUnexpectedSymbol::ErrorLexicalUnexpectedSymbol(string symbolName)
        : symbolName(symbolName), ErrorLexical(ERROR_LEXICAL_UNEXPECTED_SYMBOL, CRITICAL_ERROR) {
}

ErrorLexicalUnexpectedSymbol::ErrorLexicalUnexpectedSymbol(string symbolName, Symbol* expectedSymbol)
        : symbolName(symbolName), ErrorLexical(ERROR_LEXICAL_UNEXPECTED_SYMBOL, WARNING),
          expectedSymbol(expectedSymbol) {
}

ErrorLexicalUnexpectedSymbol::~ErrorLexicalUnexpectedSymbol() throw() {

}

string ErrorLexicalUnexpectedSymbol::whatDetails() const throw() {
    stringstream s;
    s << "Unexpected symbol read and ignored (\"" << symbolName << "\").";
    return s.str();
}

Symbol* ErrorLexicalUnexpectedSymbol::getExpectedSymbol() const {
    return expectedSymbol;
}
