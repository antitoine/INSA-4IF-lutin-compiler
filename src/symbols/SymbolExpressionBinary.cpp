#include <map>
#include "SymbolExpressionBinary.h"

using namespace std;

SymbolExpressionBinary::SymbolExpressionBinary(enum symbolIdTable idSymbol) : SymbolExpression(idSymbol) {

}


void SymbolExpressionBinary::setOperands(SymbolExpression *leftOperand, SymbolExpression *rightOperand) {
    firstOperand = leftOperand;
    secondOperand = rightOperand;
}
