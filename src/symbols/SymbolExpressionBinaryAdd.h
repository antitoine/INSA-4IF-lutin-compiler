#if !defined ( SYMBOLEXPRESSIONBINARYADD )
#define SYMBOLEXPRESSIONBINARYADD

#include "SymbolExpressionBinary.h"

/**
 * Class representing the + operator.
 */
class SymbolExpressionBinaryAdd : public SymbolExpressionBinary {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolExpressionBinaryAdd();

    virtual ~SymbolExpressionBinaryAdd();

    virtual std::string toString() const;

    float eval(map<string, StructVar *> &dicoVariables);

    virtual SymbolExpression *optimizeExpression(map<string, StructVar *> &dicoVariables);
};

#endif
