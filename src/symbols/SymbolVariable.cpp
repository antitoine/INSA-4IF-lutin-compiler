#include <map>
#include <iostream>
#include <regex>
#include "SymbolVariable.h"


SymbolVariable::SymbolVariable(std::string varName) : SymbolExpression(S_VARIABLE), name(varName)
{

}

std::string SymbolVariable::toString() {
    std::cout << "Symbol ID (id: " << id << ", name: " << name << ")" << std::endl;
}

Symbol * SymbolVariable::analyse(const std::string & stringToAnalyse, std::string & stringSymbolDetected) {
    std::smatch match;
    std::regex regex("^([a-z]+)");

    if (std::regex_search(stringToAnalyse.begin(), stringToAnalyse.end(), match, regex))
    {
        stringSymbolDetected = match[1].str().c_str();
        return new SymbolVariable(stringSymbolDetected);
    }
    else
    {
        return NULL;
    }
}

std::string SymbolVariable::getName() const {
    return name;
}

float SymbolVariable::eval(std::map<Symbol*, StructVar> & dicoVariables){
    std::map<Symbol*, StructVar>::iterator it = dicoVariables.find(this);

    //if the variable has already been initialized
    if(it->second.initialized == true){
        return it->second.value;
    }
    else{
        std::cout << "Variable " << this->getName() << "has not been declared" << std::endl;
    }
}
