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
    dicoVariables[symbolVariable->getName()]->isInitialized = true;

    // Set the variable used
    symbolVariable->setUsed();
}
