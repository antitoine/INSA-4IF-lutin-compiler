#ifndef LUT_ERRORLEXICALUNKNOWNSYMBOL_H
#define LUT_ERRORLEXICALUNKNOWNSYMBOL_H

#include <string>
#include "ErrorLexical.h"

using namespace std;

class ErrorLexicalUnknownSymbol : public ErrorLexical {
public:
    ErrorLexicalUnknownSymbol(string symbolName);
    virtual ~ErrorLexicalUnknownSymbol() throw();

protected:
    virtual string whatDetails() const throw();

    string symbolName;
};


#endif //LUT_ERRORLEXICALUNKNOWNSYMBOL_H
