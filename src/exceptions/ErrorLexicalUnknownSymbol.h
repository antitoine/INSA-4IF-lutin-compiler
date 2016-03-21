#ifndef LUT_ERRORLEXICALUNKNOWNSYMBOL_H
#define LUT_ERRORLEXICALUNKNOWNSYMBOL_H

#include <string>
#include "ErrorLexical.h"

using namespace std;

class ErrorLexicalUnknownSymbol : public ErrorLexical {
public:
    ErrorLexicalUnknownSymbol(string symbolName, int numLineError=-1, int numCharError=-1);
    virtual ~ErrorLexicalUnknownSymbol() throw();

protected:
    virtual string toStringDetails() const throw();

    string symbolName;
};


#endif //LUT_ERRORLEXICALUNKNOWNSYMBOL_H
