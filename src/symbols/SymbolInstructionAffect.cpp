//#include <boost>
#include <map>
#include "SymbolInstructionAffect.h"

SymbolInstructionAffect::SymbolInstructionAffect():SymbolInstruction(S_INSTRUCTION_AFFECT)
{

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
        std::cout << "Variable " << symbolVariable->getName() << "has not been declared" << std::endl;
    }
}

void SymbolInstructionAffect::affectExpression(SymbolExpression *expression) {
    symbolExpression = expression;
}


