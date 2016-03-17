#include <string>
#include <sstream>
#include "ErrorLexicalUnknownSymbol.h"

using namespace std;

ErrorLexicalUnknownSymbol::ErrorLexicalUnknownSymbol(string symbolName)
        : symbolName(symbolName), ErrorLexical(ERROR_LEXICAL_UNKNOWN_SYMBOL, WARNING) {
}

ErrorLexicalUnknownSymbol::~ErrorLexicalUnknownSymbol() throw() {

}

string ErrorLexicalUnknownSymbol::whatDetails() const throw() {
    stringstream s;
    s << "Unknown symbol read and ignored (\"" << symbolName << "\").";
    return s.str();
}
