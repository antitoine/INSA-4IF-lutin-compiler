#ifndef LUT_ERRORLEXICALUNEXPECTEDSYMBOL_H
#define LUT_ERRORLEXICALUNEXPECTEDSYMBOL_H

#include <string>
#include "ErrorLexical.h"
#include "../symbols/Symbol.h"

using namespace std;

class ErrorLexicalUnexpectedSymbol : public ErrorLexical {
public:
    ErrorLexicalUnexpectedSymbol(const string & symbolName, int numLine, int numChar);
    ErrorLexicalUnexpectedSymbol(const string & symbolName, Symbol* expectedSymbol, int numLine, int numChar);
    virtual ~ErrorLexicalUnexpectedSymbol() throw();
    Symbol* getExpectedSymbol() const;

protected:
    virtual string toStringDetails() const throw();

    string symbolName;

    Symbol* expectedSymbol;
};

#endif //LUT_ERRORLEXICALUNEXPECTEDSYMBOL_H
