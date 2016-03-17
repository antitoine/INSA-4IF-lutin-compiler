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

Symbol * SymbolVariable::analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected, map<string, StructVar*>& dicoVariables) {
    MatchingResult result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::IDENTIFICATEUR);

    if (result.matched)
    {
        stringToAnalyse = result.stringConsumed;
        stringSymbolDetected = result.stringMatched;

        map<string, StructVar *>::iterator it = dicoVariables.find(result.stringMatched);
        if (it != dicoVariables.end()) { // The variable exists
            return it->second->ptSymbol;
        } else {
            // Trim the name
            string varName = result.stringMatched;
            size_t first = varName.find_first_not_of(' ');
            size_t last = varName.find_last_not_of(' ');
            return new SymbolVariable(varName.substr(first, (last-first+1)));
        }
    }
    else
    {
        return NULL;
    }
}

std::string SymbolVariable::getName() const {
    return name;
}

float SymbolVariable::eval(map<string, StructVar*>& dicoVariables){
    map<string, StructVar*>::iterator it = dicoVariables.find(name);

    //if the variable has already been initialized
    if(it->second->isInitialized == true){
        return it->second->value;
    }
    else{
        std::cout << "Variable " << this->getName() << "has not been declared" << std::endl;
    }
}
