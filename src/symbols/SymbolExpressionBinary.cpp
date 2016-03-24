#include <map>
#include <list>
#include "SymbolExpressionBinary.h"
#include "SymbolNumber.h"
#include "../exceptions/Error.h"

using namespace std;

SymbolExpressionBinary::SymbolExpressionBinary(enum symbolIdTable idSymbol) : SymbolExpression(idSymbol) {
    firstOperand = NULL;
    secondOperand = NULL;
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

SymbolExpression *SymbolExpressionBinary::optimizeExpression(map<string, StructVar *> &dicoVariables) {
    SymbolExpression * firstOperandOptimized = firstOperand->optimizeExpression(dicoVariables);

    if (firstOperandOptimized != firstOperand) {
        firstOperand->detachExpressions();
        delete firstOperand;
        firstOperand = firstOperandOptimized;
    }

    SymbolExpression * secondOperandOptimized  = secondOperand->optimizeExpression(dicoVariables);

    if (secondOperandOptimized != secondOperand) {
        secondOperand->detachExpressions();
        delete secondOperand;
        secondOperand = secondOperandOptimized;
    }

    // Merge the numeric symbols
    if (firstOperand->getId() == S_NUMBER && secondOperand->getId() == S_NUMBER) {
        return new SymbolNumber(eval(dicoVariables));
    }

    return NULL;
}

void SymbolExpressionBinary::detachExpressions() {
    firstOperand = NULL;
    secondOperand = NULL;
}
