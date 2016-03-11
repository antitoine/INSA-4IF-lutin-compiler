//#include <boost>
#include <map>
#include "SymbolInstructionAffect.h"

SymbolInstructionAffect::SymbolInstructionAffect():SymbolInstruction(S_INSTRUCTION_AFFECT)
{

}

void SymbolInstructionAffect::execute(std::map<Symbol*, StructVar> & dicoVariables) {
    StructVar s = {symbolExpression->eval(dicoVariables), false, true};
    std::map<Symbol*, StructVar>::iterator it = dicoVariables.find(symbolVariable);

    //if the variable is already existing in the map
    if(it != dicoVariables.end()){
        dicoVariables[symbolVariable]=s;
    }
    else{
        std::cout << "Variable " << symbolVariable->getName() << "has not been declared" << std::endl;
    }
}

