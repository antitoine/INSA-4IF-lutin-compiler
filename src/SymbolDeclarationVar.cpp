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