#include <map>
#include <list>
#include <sstream>
#include "SymbolInstructionAffect.h"
#include "../exceptions/ErrorComposite.h"

using namespace std;

SymbolInstructionAffect::SymbolInstructionAffect() : SymbolInstruction(S_INSTRUCTION_AFFECT) {
    symbolVariable = NULL;
    symbolExpression = NULL;
}

SymbolInstructionAffect::SymbolInstructionAffect(SymbolVariable *variable)
        : SymbolInstruction(S_INSTRUCTION_AFFECT), symbolVariable(variable) {
}

SymbolInstructionAffect::~SymbolInstructionAffect() {
    if (symbolExpression != NULL) {
        delete symbolExpression;
    }

    if (symbolVariable != NULL) {
        delete symbolVariable;
    }
}

string SymbolInstructionAffect::toString() const {
    stringstream s;
    if (symbolExpression == NULL) {
        return symbolVariable->toString();
    }
    s << symbolVariable->toString() << " := " << symbolExpression->toString() << ";\n";
    return s.str();
}

void SymbolInstructionAffect::execute(map<string, StructVar *> &dicoVariables) {
    // Check done before execution: variable is in dico
    StructVar *ptS = dicoVariables[symbolVariable->getName()];
    ptS->value = symbolExpression->eval(dicoVariables);
}

void SymbolInstructionAffect::affectExpression(SymbolExpression *expression) {
    symbolExpression = expression;
}

void SymbolInstructionAffect::check(map<string, StructVar *> &dicoVariables) {
    // Check the expression
    list<Error *> *exprErrors = symbolExpression->checkEval(dicoVariables);

    // Check variable to affect
    try {
        symbolVariable->check(dicoVariables, true);
    } catch (Error const &error) {
        if (error.getLevel() == WARNING) {
            if (exprErrors != NULL) {
                throw ErrorComposite(exprErrors);
            } else {
                throw;
            }
        } else {
            throw;
        }
    }

    // Only the expression is incorrect
    if (exprErrors != NULL) {
        throw ErrorComposite(exprErrors);
    }

    // If the check is correct, the variable is set as initialized
    StructVar *pt = dicoVariables[symbolVariable->getName()];
    pt->isInitialized = true;
}

Symbol *SymbolInstructionAffect::optimize(map<string, StructVar *> &dicoVariables) {
    symbolExpression = symbolExpression->optimizeExpression(dicoVariables);
    return this;
}
