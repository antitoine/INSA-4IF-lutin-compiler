#ifndef LUT_ERRORLEXICALUNEXPECTEDSYMBOL_H
#define LUT_ERRORLEXICALUNEXPECTEDSYMBOL_H

#include <string>
#include "ErrorLexical.h"
#include "../symbols/Symbol.h"

using namespace std;

class ErrorLexicalUnexpectedSymbol : public ErrorLexical {
public:
    ErrorLexicalUnexpectedSymbol(string symbolName);
    ErrorLexicalUnexpectedSymbol(string symbolName, Symbol* expectedSymbol);
    virtual ~ErrorLexicalUnexpectedSymbol() throw();
    Symbol* getExpectedSymbol() const;

protected:
    virtual string whatDetails() const throw();

    string symbolName;

    Symbol* expectedSymbol;
};

#endif //LUT_ERRORLEXICALUNEXPECTEDSYMBOL_H
