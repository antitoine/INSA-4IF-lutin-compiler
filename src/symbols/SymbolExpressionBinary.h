#if !defined ( SYMBOLEXPRESSIONBINARY )
#define SYMBOLEXPRESSIONBINARY

#include "../exceptions/Error.h"
#include "SymbolExpression.h"

using namespace std;

class SymbolExpressionBinary : public SymbolExpression {
public:
    SymbolExpressionBinary(enum symbolIdTable idSymbol);
    virtual std::string toString() const = 0;
    virtual float eval(std::map<string, StructVar*> &dicoVariables) = 0;
    virtual void setOperands(SymbolExpression * leftOperand, SymbolExpression * rightOperand);
    virtual list<Error*> * checkEval(map<string, StructVar*>& dicoVariables);

    virtual ~SymbolExpressionBinary();

protected:
    SymbolExpression *firstOperand;
    SymbolExpression *secondOperand;

};

#endif
