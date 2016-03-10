#include <map>
#include "SymbolDeclarationConst.h"
#include "symbol.h"

using namespace std;

SymbolDeclarationConst::SymbolDeclarationConst() : SymbolDeclaration(S_DECLARATION_CONST)
{

}

Symbol * SymbolDeclarationConst::analyse(const std::string & stringToAnalyse, std::string & stringSymbolDetected) {
    // TODO
    stringSymbolDetected = "const ";
    return new SymbolDeclarationConst();
}