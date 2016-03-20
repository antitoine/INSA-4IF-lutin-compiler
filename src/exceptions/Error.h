#ifndef LUT_ERROR_H
#define LUT_ERROR_H

#include <exception>
#include <string>
using namespace std;

enum TypeErrorLevel {
    WARNING = 0,
    CRITICAL_ERROR = 1
};

enum TypeError {
    ERROR_COMPOSITE = 0,
    ERROR_SEMANTIC_VAR_ALREADY_DECLARED,
    ERROR_SEMANTIC_VAR_NOT_DECLARED,
    ERROR_SEMANTIC_VAR_IS_CONST,
    ERROR_SEMANTIC_VAR_NOT_INITIALIZED,
    ERROR_SEMANTIC_VAR_NOT_USED,
    ERROR_LEXICAL_UNKNOWN_SYMBOL,
    ERROR_LEXICAL_UNEXPECTED_SYMBOL
};

class Error : public exception {
public:
    Error(int number, int level=CRITICAL_ERROR) throw();
    virtual ~Error() throw();

    virtual string whatDefault() const throw();
    virtual string what(int line, int charPos) const throw();

    int getLevel() const throw();
    int getNumber() const throw();

protected:
    virtual string whatDetails() const throw() = 0;

    // Error number
    int number;

    // Error level
    int level;
};


#endif //LUT_ERROR_H
