#ifndef LUT_ERRORLEXICALUNEXPECTEDSYMBOL_H
#define LUT_ERRORLEXICALUNEXPECTEDSYMBOL_H

#include <string>
#include "ErrorLexical.h"
#include "../symbols/Symbol.h"

using namespace std;

/**
 * Error: unexpected symbol encountered.
 */
class ErrorLexicalUnexpectedSymbol : public ErrorLexical {
public:
    /**
     * Basic constructor.
     * @param symbolName Unexpected symbol's name.
     * @param numLine Error line
     * @param numChar Error char position
     */
    ErrorLexicalUnexpectedSymbol(const string &symbolName, int numLine, int numChar);

    /**
     * Constructor with expected symbol. Exception as warning.
     * @param symbolName Unexpected symbol's name.
     * @param numLine Error line
     * @param numChar Error char position
     * @param exprectedSymbol Symbol to use to replace the unexpected symbol.
     */
    ErrorLexicalUnexpectedSymbol(const string &symbolName, int numLine, int numChar, Symbol *expectedSymbol);

    /**
     * Constructor with ignored symbol. Exception as warning.
     * @param symbolName Unexpected symbol's name.
     * @param numLine Error line
     * @param numChar Error char position
     * @param ignoreSymbol If true, ignore the unexpected symbol, without replace it by another.
     */
    ErrorLexicalUnexpectedSymbol(const string &symbolName, int numLine, int numChar, bool ignoreSymbol);

    virtual ~ErrorLexicalUnexpectedSymbol() throw();

    /**
     * @return The expected symbol or NULL if the exception can be fixed.
     */
    Symbol *getExpectedSymbol() const;

    /**
     * @return True if the unexpected symbol can be ignored, false otherwise.
     */
    bool isSymbolIgnored() const;

protected:
    virtual string toStringDetails() const throw();

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /** Unexpected symbol's name */
    string symbolName;

    /** True if the unexpected symbol can be ignored. */
    bool isIgnored;

    /** The expected symbol */
    Symbol *expectedSymbol;
};

#endif //LUT_ERRORLEXICALUNEXPECTEDSYMBOL_H
