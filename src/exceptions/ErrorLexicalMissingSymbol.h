#ifndef LUT_ERRORLEXICALMISSINGSYMBOL_H
#define LUT_ERRORLEXICALMISSINGSYMBOL_H

#include <string>
#include "ErrorLexical.h"
#include "../symbols/Symbol.h"

using namespace std;

/**
 * Error: a symbol is missing during the lexical analysis.
 */
class ErrorLexicalMissingSymbol : public ErrorLexical {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    ErrorLexicalMissingSymbol(int numLine, int numChar, Symbol * missingSymbol) throw();
    virtual ~ErrorLexicalMissingSymbol() throw();

    /**
     * @return The missing symbol.
     */
    Symbol* getMissingSymbol() const;

protected:
    virtual string toStringDetails() const throw();

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    Symbol* missingSymbol;
};


#endif //LUT_ERRORLEXICALMISSINGSYMBOL_H
