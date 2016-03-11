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
    std::map<Symbol*, StructVar>::iterator it = dicoVariables.find(symbolVariable);

    //if the variable is already existing in the map
    if(it != dicoVariables.end()){
        dicoVariables[symbolVariable]=s;
    }
    else{
        std::cout << "Variable " << symbolVariable->getName() << "has not been declared" << std::endl;
    }
}
