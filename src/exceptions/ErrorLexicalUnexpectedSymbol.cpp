#include <string>
#include <sstream>
#include "ErrorLexicalUnexpectedSymbol.h"

using namespace std;

ErrorLexicalUnexpectedSymbol::ErrorLexicalUnexpectedSymbol(const string & symbolName, int numLine, int numChar)
        : ErrorLexical(ERROR_LEXICAL_UNEXPECTED_SYMBOL, ERROR, numLine, numChar), symbolName(symbolName), isIgnored(false) {
}

ErrorLexicalUnexpectedSymbol::ErrorLexicalUnexpectedSymbol(const string & symbolName, int numLine, int numChar, Symbol* expectedSymbol)
        : ErrorLexical(ERROR_LEXICAL_UNEXPECTED_SYMBOL, WARNING, numLine, numChar), symbolName(symbolName),
          expectedSymbol(expectedSymbol), isIgnored(false) {
}

ErrorLexicalUnexpectedSymbol::ErrorLexicalUnexpectedSymbol(const string &symbolName, int numLine, int numChar,
                                                           bool ignoreSymbol)
        : ErrorLexical(ERROR_LEXICAL_UNEXPECTED_SYMBOL, WARNING, numLine, numChar), symbolName(symbolName),
          expectedSymbol(expectedSymbol), isIgnored(ignoreSymbol) {
    if (!isIgnored) {
        level = ERROR;
    }
}

ErrorLexicalUnexpectedSymbol::~ErrorLexicalUnexpectedSymbol() throw() {

}

string ErrorLexicalUnexpectedSymbol::toStringDetails() const throw() {
    stringstream s;
    if (this->getLevel() == WARNING) {
        if (isIgnored) {
            s << "Unexpected symbol read and ignored (\"" << symbolName << "\").";
        } else {
            s << "Unexpected symbol read (\"" << symbolName << "\") and replaced by \"" << expectedSymbol->toString() << "\".";
        }
    } else {
        s << "Unexpected symbol read and caused program failure (\"" << symbolName << "\").";
    }
    return s.str();
}

Symbol* ErrorLexicalUnexpectedSymbol::getExpectedSymbol() const {
    return expectedSymbol;
}


bool ErrorLexicalUnexpectedSymbol::isSymbolIgnored() const {
    return isIgnored;
}
