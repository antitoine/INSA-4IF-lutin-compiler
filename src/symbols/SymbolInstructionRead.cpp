//#include <boost>
#include <map>
#include "SymbolInstructionRead.h"


SymbolInstructionRead::SymbolInstructionRead():SymbolInstruction(S_INSTRUCTION_READ)
{

}

void SymbolInstructionRead::execute(std::map<Symbol*, StructVar> & dicoVariables){
    float userValue;
    std::cin >> userValue;
    StructVar s = {userValue, false, true};

    //we check if the variable is already in the dico
    bool exist = false;
    for(auto const &it : dicoVariables) {
        if(dynamic_cast<SymbolVariable*>(it.first)->getName() == symbolVariable->getName()){
            exist = true;
            break;
        }
    }

    //if the variable is already existing in the map
    if(exist){
        dicoVariables[symbolVariable]=s;
    }
    else{
        std::cout << "Variable " << symbolVariable->getName() << "has not been declared" << std::endl;
    }
}

void SymbolInstructionRead::affectExpression(SymbolExpression *expression) {
    // Nothing to do
}
