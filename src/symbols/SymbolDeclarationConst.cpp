#include <map>
#include <iostream>
#include <regex>
#include "SymbolDeclarationConst.h"
#include "symbol.h"


SymbolDeclarationConst::SymbolDeclarationConst() : SymbolDeclaration(S_DECLARATION_CONST)
{

}

std::string SymbolDeclarationConst::toString() {
    std::cout << "Symbol CONST (id: " << id << ")" << std::endl;
}

Symbol * SymbolDeclarationConst::analyse(const std::string & stringToAnalyse, std::string & stringSymbolDetected) {
    std::smatch match;
    std::regex regex("^(const )");

    if (std::regex_search(stringToAnalyse.begin(), stringToAnalyse.end(), match, regex))
    {
        stringSymbolDetected = match[1].str().c_str();
        return new SymbolDeclarationConst();
    }
    else
    {
        return NULL;
    }
}

void SymbolDeclarationConst::execute(std::map<Symbol*, StructVar> & dicoVariables) {
    //For each constant declaration, add it to dicoVariable
    for (auto const &v : constants) {
        StructVar s = {v.second, true, true};
        std::pair<std::map<Symbol*, StructVar>::iterator, bool> variableExist = dicoVariables.insert(std::pair<Symbol *, StructVar>(v.first, s));
        if(variableExist.second == false){
            std::cout << "Variable " << v.first->getName() << "has already been declared" << std::endl;
        }
    }
}