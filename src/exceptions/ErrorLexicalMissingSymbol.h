#ifndef LUT_ERRORLEXICALMISSINGSYMBOL_H
#define LUT_ERRORLEXICALMISSINGSYMBOL_H

#include <string>
#include "ErrorLexical.h"
#include "../symbols/Symbol.h"

using namespace std;

class ErrorLexicalMissingSymbol : public ErrorLexical {
public:
    ErrorLexicalMissingSymbol(int numLine, int numChar, Symbol * missingSymbol) throw();
    virtual ~ErrorLexicalMissingSymbol() throw();

    Symbol* getMissingSymbol() const;

protected:
    virtual string toStringDetails() const throw();

    Symbol* missingSymbol;
};


#endif //LUT_ERRORLEXICALMISSINGSYMBOL_H
