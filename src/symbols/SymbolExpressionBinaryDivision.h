#if !defined ( SYMBOLEXPRESSIONBINARYDIVISION )
#define SYMBOLEXPRESSIONBINARYDIVISION

#include "SymbolExpressionBinary.h"

using namespace std;

/**
 * Class representing the / operator.
 */
class SymbolExpressionBinaryDivision : public SymbolExpressionBinary {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    SymbolExpressionBinaryDivision();

    virtual ~SymbolExpressionBinaryDivision();

    virtual string toString() const;

    float eval(map<string, StructVar *> &dicoVariables);

    virtual SymbolExpression *optimizeExpression(map<string, StructVar *> &dicoVariables);
};

#endif
