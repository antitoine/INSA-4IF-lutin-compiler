#include <string>
#include <sstream>
#include "ErrorLexicalUnknownSymbol.h"

using namespace std;

ErrorLexicalUnknownSymbol::ErrorLexicalUnknownSymbol(string symbolName, int numLineError, int numCharError)
        : ErrorLexical(ERROR_LEXICAL_UNKNOWN_SYMBOL, WARNING, numLineError, numCharError), symbolName(symbolName) {
}

ErrorLexicalUnknownSymbol::~ErrorLexicalUnknownSymbol() throw() {

}

string ErrorLexicalUnknownSymbol::toStringDetails() const throw() {
    stringstream s;
    size_t first = symbolName.find_first_not_of(' ');
    size_t last = symbolName.find_last_not_of(' ');
    s << "Unknown symbol read and ignored (\"" << symbolName.substr(first, (last - first + 1)) << "\").";
    return s.str();
}
