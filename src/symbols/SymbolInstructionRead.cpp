//#include <boost>
#include <map>
#include "SymbolInstructionRead.h"


SymbolInstructionRead::SymbolInstructionRead():SymbolInstruction(S_INSTRUCTION_READ)
{

}

void SymbolInstructionRead::execute(map<string, StructVar*>& dicoVariables){
    float userValue;
    std::cin >> userValue;

    // We check if the variable is already in the dico
    map<string, StructVar *>::iterator it = dicoVariables.find(symbolVariable->getName());
    if (it != dicoVariables.end()) { // The variable exists
        StructVar * ptS = it->second;
        ptS->value = userValue;
        ptS->isInitialized = true;
    } else {
        // TODO : Exception
        std::cout << "Variable " << symbolVariable->getName() << "has not been declared" << std::endl;
    }
}

void SymbolInstructionRead::affectExpression(SymbolExpression *expression) {
    // Nothing to do
}
