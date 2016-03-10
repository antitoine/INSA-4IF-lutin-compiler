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
    std::regex regex("^(var )");

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