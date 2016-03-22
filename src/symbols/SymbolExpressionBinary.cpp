#include <map>
#include <list>
#include "SymbolExpressionBinary.h"
#include "../exceptions/Error.h"

using namespace std;

SymbolExpressionBinary::SymbolExpressionBinary(enum symbolIdTable idSymbol) : SymbolExpression(idSymbol) {

}


void SymbolExpressionBinary::setOperands(SymbolExpression *leftOperand, SymbolExpression *rightOperand) {
    firstOperand = leftOperand;
    secondOperand = rightOperand;
}


list<Error *> * SymbolExpressionBinary::checkEval(map<string, StructVar*>& dicoVariables) {
    std::list<Error *> * errors = NULL;
    std::list<Error *> * operandErrors = NULL;

    operandErrors = firstOperand->checkEval(dicoVariables);
    if (operandErrors != NULL) {
        errors = operandErrors;
    }

    operandErrors = secondOperand->checkEval(dicoVariables);
    if (operandErrors != NULL) {
        if (errors == NULL) {
            errors = operandErrors;
        } else {
            errors->insert(errors->end(), operandErrors->begin(), operandErrors->end());
            delete operandErrors;
        }
    }

    return errors;
}

SymbolExpressionBinary::~SymbolExpressionBinary() {
    if (firstOperand != NULL) {
        delete firstOperand;
    }

    if (secondOperand != NULL) {
        delete secondOperand;
    }
}
