#ifndef LUT_ERROR_H
#define LUT_ERROR_H

#include <exception>
#include <string>

using namespace std;

enum TypeErrorLevel {
    WARNING = 0,
    ERROR = 1
};

enum TypeError {
    ERROR_SEMANTIC_VAR_NOT_USED = -1, // WARNING only
    ERROR_COMPOSITE = 0, // Contains other errors
    ERROR_WRONG_ARGUMENTS,
    ERROR_FILE_NOT_FOUND,
    ERROR_SEMANTIC_VAR_ALREADY_DECLARED,
    ERROR_SEMANTIC_VAR_NOT_DECLARED,
    ERROR_SEMANTIC_VAR_IS_CONST,
    ERROR_SEMANTIC_VAR_NOT_INITIALIZED,
    ERROR_LEXICAL_UNKNOWN_SYMBOL,
    ERROR_LEXICAL_UNEXPECTED_SYMBOL,
    ERROR_LEXICAL_MISSING_SYMBOL,
    ERROR_SEMANTIC_INCORRECT_NUM_VALUE
};

/**
 * Abstract class which inherits C++ Exception, representing all the program errors.
 */
class Error : public exception {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    /**
     * Constructor.
     * @number : Error's id
     * @level : ERROR by default, can be only WARNING
     * @numLineError : Optional, line number where the error was encountered.
     * @numCharError : Optional, char position where the error was encountered.
     */
    Error(int number, int level = ERROR, int numLineError = -1, int numCharError = -1) throw();

    /**
     * Destructor.
     */
    virtual ~Error() throw();

    /**
     * Override. Call toString() method.
     */
    virtual const char *what() const throw();

    /**
     * Describe the error.
     * @return Error's description.
     */
    virtual string toString() const throw();

    /**
     * Describe the error with new position.
     * @linePos : New line error position.
     * @charPos : New char error position.
     * @return Error's description.
     */
    virtual string toString(int linePos, int charPos) const throw();

    /**
     * @return The error's level.
     */
    int getLevel() const throw();

    /**
     * @return The error's id.
     */
    int getNumber() const throw();

protected:
    /**
     * Describe the error in details (depends on class realization).
     * @return Details.
     */
    virtual string toStringDetails() const throw() = 0;

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:

    /** Error number. */
    int number;

    /** Error level. */
    int level;

    /** Error line position. */
    int numLineError;

    /** Error char position. */
    int numCharError;
};

#endif //LUT_ERROR_H
