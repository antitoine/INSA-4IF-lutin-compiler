#if !defined ( SYMBOLEXPRESSIONBINARYSUBSTRACT )
#define SYMBOLEXPRESSIONBINARYSUBSTRACT

#include "SymbolExpressionBinary.h"

using namespace std;

/**
 * Class representing the - operator.
 */
class SymbolExpressionBinarySubstract : public SymbolExpressionBinary {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolExpressionBinarySubstract();

    virtual ~SymbolExpressionBinarySubstract();

    virtual string toString() const;

    float eval(map<string, StructVar *> &dicoVariables);

    virtual SymbolExpression *optimizeExpression(map<string, StructVar *> &dicoVariables);
};

#endif
