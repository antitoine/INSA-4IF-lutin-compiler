#include <map>
#include <ostream>
#include <iostream>
#include <regex>
#include "SymbolDeclarationVar.h"


SymbolDeclarationVar::SymbolDeclarationVar()
        :SymbolDeclaration(S_DECLARATION_VAR)
{

}

std::string SymbolDeclarationVar::toString() {
    std::cout << "Symbol VAR (id: " << id << ")" << std::endl;
}

Symbol * SymbolDeclarationVar::analyse(const std::string & stringToAnalyse, std::string & stringSymbolDetected) {
    std::smatch match;
    std::regex regex("^(var )");

    if (std::regex_search(stringToAnalyse.begin(), stringToAnalyse.end(), match, regex))
    {
        stringSymbolDetected = match[1].str().c_str();
        return new SymbolDeclarationVar();
    }
    else
    {
        return NULL;
    }
}

void SymbolDeclarationVar::computeSublistSymbols(const std::list<Symbol*> & symbolsToCompute) {
    std::cout << "compute !!" << std::endl;
    for (Symbol * s : symbolsToCompute) {
        if (SymbolVariable* var = dynamic_cast<SymbolVariable*>(s)) {
            std::cout << "var detected!" << std::endl;
        }
    }
}

void SymbolDeclarationVar::execute(std::map<Symbol*, StructVar> & dicoVariables) {
    for (SymbolVariable * v : variables) {
        StructVar s = {0, false, false};
        std::pair<std::map<Symbol*, StructVar>::iterator, bool> variableExist = dicoVariables.insert(std::pair<Symbol *, StructVar>(v, s));
        if(variableExist.second == false){
            std::cout << "Variable " << v->getName() << "has already been declared" << std::endl;
        }

    }
}
