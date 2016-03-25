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
    ERROR_COMPOSITE = 0,
    ERROR_SEMANTIC_VAR_ALREADY_DECLARED,
    ERROR_SEMANTIC_VAR_NOT_DECLARED,
    ERROR_SEMANTIC_VAR_IS_CONST,
    ERROR_SEMANTIC_VAR_NOT_INITIALIZED,
    ERROR_SEMANTIC_VAR_NOT_USED,
    ERROR_LEXICAL_UNKNOWN_SYMBOL,
    ERROR_LEXICAL_UNEXPECTED_SYMBOL,
    ERROR_LEXICAL_MISSING_SYMBOL,
    ERROR_SEMANTIC_INCORRECT_NUM_VALUE
};

class Error : public exception {
public:
    Error(int number, int level=ERROR, int numLineError=-1, int numCharError=-1) throw();
    virtual ~Error() throw();

    virtual const char* what() const throw();
    virtual string toString() const throw();
    virtual string toString(int linePos, int charPos) const throw();

    int getLevel() const throw();
    int getNumber() const throw();

protected:
    virtual string toStringDetails() const throw() = 0;

    // Error number
    int number;

    // Error level
    int level;

    int numLineError;
    int numCharError;
};


#endif //LUT_ERROR_H
