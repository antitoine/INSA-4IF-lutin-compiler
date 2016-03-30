#ifndef LUT_ERRORLEXICALUNKNOWNSYMBOL_H
#define LUT_ERRORLEXICALUNKNOWNSYMBOL_H

#include <string>
#include "ErrorLexical.h"

using namespace std;

/**
 * Error: Unknown symbol read during lexical analysis.
 */
class ErrorLexicalUnknownSymbol : public ErrorLexical {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    ErrorLexicalUnknownSymbol(string symbolName, int numLineError = -1, int numCharError = -1);

    virtual ~ErrorLexicalUnknownSymbol() throw();

protected:
    virtual string toStringDetails() const throw();

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    string symbolName;
};


#endif //LUT_ERRORLEXICALUNKNOWNSYMBOL_H
