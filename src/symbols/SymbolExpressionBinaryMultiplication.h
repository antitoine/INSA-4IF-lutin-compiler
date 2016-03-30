#if !defined ( SYMBOLEXPRESSIONBINARYMULTIPLICATION )
#define SYMBOLEXPRESSIONBINARYMULTIPLICATION

#include "SymbolExpressionBinary.h"

using namespace std;

/**
 * Class representing the * operator.
 */
class SymbolExpressionBinaryMultiplication : public SymbolExpressionBinary {
// METHODS ------------------------------------------------------------------------------------------------------------- 
public:
    SymbolExpressionBinaryMultiplication();

    virtual ~SymbolExpressionBinaryMultiplication();

    virtual string toString() const;

    float eval(map<string, StructVar *> &dicoVariables);

    virtual SymbolExpression *optimizeExpression(map<string, StructVar *> &dicoVariables);
};

#endif
