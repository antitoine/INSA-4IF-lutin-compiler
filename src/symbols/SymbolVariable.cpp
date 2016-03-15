#include <map>
#include <iostream>
#include <regex>
#include "SymbolVariable.h"
#include "RegexSymbol.h"


SymbolVariable::SymbolVariable(std::string varName) : SymbolExpression(S_VARIABLE), name(varName)
{

}

std::string SymbolVariable::toString() {
    std::cout << "Symbol ID (id: " << id << ", name: " << name << ")" << std::endl;
}

Symbol * SymbolVariable::analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected) {
    MatchingResult result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::IDENTIFICATEUR);

    if (result.matched)
    {
        stringToAnalyse = result.stringConsumed;
        stringSymbolDetected = result.stringMatched;
        return new SymbolVariable(result.stringMatched);
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
