#include <map>
#include <list>
#include "SymbolInstructionAffect.h"
#include "../exceptions/ErrorComposite.h"

using namespace std;

SymbolInstructionAffect::SymbolInstructionAffect(): SymbolInstruction(S_INSTRUCTION_AFFECT)
{

}

string SymbolInstructionAffect::toString() const {
    return symbolVariable->toString() + " := " + symbolExpression->toString() + ";\n";
}

SymbolInstructionAffect::SymbolInstructionAffect(SymbolVariable *variable)
        :SymbolInstruction(S_INSTRUCTION_AFFECT), symbolVariable(variable) {
}

void SymbolInstructionAffect::execute(map<string, StructVar*>& dicoVariables) {
    // We check if the variable is already in the dico
    map<string, StructVar *>::iterator it = dicoVariables.find(symbolVariable->getName());

    if (it != dicoVariables.end()) { // The variable exists
        StructVar * ptS = it->second;
        ptS->value = symbolExpression->eval(dicoVariables);
        ptS->isInitialized = true;
    } else {
        // TODO : Exception
        std::cout << "Variable " << symbolVariable->getName() << " has not been declared" << std::endl;
    }
}

void SymbolInstructionAffect::affectExpression(SymbolExpression *expression) {
    symbolExpression = expression;
}


void SymbolInstructionAffect::check(map<string, StructVar *> &dicoVariables) {
    // Check the expression
    std::list<Error*> * exprErrors = symbolExpression->checkEval(dicoVariables);

    // Check variable to affect
    try {
        symbolVariable->check(dicoVariables);
    } catch (Error const& error) {
        if (error.getLevel() == WARNING) {
            if (exprErrors != NULL) {
                ErrorComposite e = ErrorComposite(exprErrors);
                delete exprErrors;
                throw e;
            } else {
                throw;
            }
        } else {
            throw;
        }
    }
}
