#include <map>
#include <list>
#include <sstream>
#include "SymbolInstructionAffect.h"
#include "../exceptions/ErrorComposite.h"

using namespace std;

SymbolInstructionAffect::SymbolInstructionAffect(): SymbolInstruction(S_INSTRUCTION_AFFECT)
{

}

string SymbolInstructionAffect::toString() const {
    stringstream s;
    s << symbolVariable->toString() << " := " << symbolExpression->toString() << ";\n";
    return s.str();
}

SymbolInstructionAffect::SymbolInstructionAffect(SymbolVariable *variable)
        :SymbolInstruction(S_INSTRUCTION_AFFECT), symbolVariable(variable) {
}

void SymbolInstructionAffect::execute(map<string, StructVar*>& dicoVariables) {
    // Check done before execution: variable in dico
    StructVar * ptS = dicoVariables[symbolVariable->getName()];
    ptS->value = symbolExpression->eval(dicoVariables);
}

void SymbolInstructionAffect::affectExpression(SymbolExpression *expression) {
    symbolExpression = expression;
}


void SymbolInstructionAffect::check(map<string, StructVar *> &dicoVariables) {
    // Check the expression
    std::list<Error*> * exprErrors = symbolExpression->checkEval(dicoVariables);

    // Check variable to affect
    try {
        symbolVariable->check(dicoVariables, true);
    } catch (Error const& error) {
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
    StructVar * pt = dicoVariables[symbolVariable->getName()];
    pt->isInitialized = true;

    // Set the variable as used
    pt->isUsed = true;
}

SymbolInstructionAffect::~SymbolInstructionAffect() {
    if (symbolExpression != NULL) {
        delete symbolExpression;
    }

    if (symbolVariable != NULL) {
        delete symbolVariable;
    }
}
