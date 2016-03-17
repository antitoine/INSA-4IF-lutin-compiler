//#include <boost>
#include <map>
#include "SymbolInstructionAffect.h"

SymbolInstructionAffect::SymbolInstructionAffect():SymbolInstruction(S_INSTRUCTION_AFFECT)
{

}

void SymbolInstructionAffect::execute(std::map<Symbol*, StructVar> & dicoVariables) {
    StructVar s = {symbolExpression->eval(dicoVariables), false, true};

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

