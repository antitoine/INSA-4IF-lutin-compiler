#include <map>
#include <iostream>
#include "SymbolDeclarationConst.h"
#include "symbol.h"
#include "RegexSymbol.h"
#include <re2/re2.h>


SymbolDeclarationConst::SymbolDeclarationConst() : SymbolDeclaration(S_DECLARATION_CONST)
{

}

std::string SymbolDeclarationConst::toString() {
    std::cout << "Symbol CONST (id: " << id << ")" << std::endl;
}

Symbol * SymbolDeclarationConst::analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected) {
    MatchingResult result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::CONST);

    if (result.matched)
    {
        stringToAnalyse = result.stringConsumed;
        stringSymbolDetected = result.stringMatched;
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

        //we check if the variable is already in the dico
        bool exist = false;
        for(auto const &it : dicoVariables) {
            if(dynamic_cast<SymbolVariable*>(it.first)->getName() == v.first->getName()){
                exist = true;
                break;
            }
        }

        if(exist){
            std::cout << "Variable " << v.first->getName() << "has already been declared" << std::endl;
        }
        else{
            dicoVariables.insert(std::pair<Symbol *, StructVar>(v.first, s));
        }
    }
}

void SymbolDeclarationConst::addConstant(SymbolVariable *pVariable) {
    temporaryPtVariable = pVariable;
}

void SymbolDeclarationConst::addConstantValue(float constantValue) {
    if (temporaryPtVariable != NULL) {
        constants.insert(pair<SymbolVariable*, float>(temporaryPtVariable, constantValue));
        temporaryPtVariable = NULL;
    } else {
        cerr << "No constant to affect a value." << endl;
    }
}
