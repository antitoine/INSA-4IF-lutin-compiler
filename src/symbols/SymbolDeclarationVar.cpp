#include <map>
#include <ostream>
#include <iostream>
#include "SymbolDeclarationVar.h"
#include "SymbolVariable.h"
#include "RegexSymbol.h"

using namespace std;

SymbolDeclarationVar::SymbolDeclarationVar()
        :SymbolDeclaration(S_DECLARATION_VAR)
{

}

string SymbolDeclarationVar::toString() {
    cout << "Symbol VAR (id: " << id << ")" << endl;
}

Symbol * SymbolDeclarationVar::analyse(string & stringToAnalyse, string & stringSymbolDetected) {
    MatchingResult result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::VAR);

    if (result.matched)
    {
        stringToAnalyse = result.stringConsumed;
        stringSymbolDetected = result.stringMatched;
        return new SymbolDeclarationVar();
    }
    else
    {
        return NULL;
    }
}

void SymbolDeclarationVar::execute(map<Symbol*, StructVar> & dicoVariables) {
    cout << "#TRACE: execute declaration var" << endl;
    for (SymbolVariable * v : variables) {
        StructVar s = {0, false, false};
        bool exist = false;

        //we check if the variable is already in the dico
        for(auto const &it : dicoVariables) {
            if(dynamic_cast<SymbolVariable*>(it.first)->getName() == v->getName()){
                exist = true;
                break;
            }
        }

        if(exist){
            cout << "Variable " << ((SymbolVariable*)v)->getName() << "has already been declared" << endl;
        }
        else{
            dicoVariables.insert(pair<Symbol *, StructVar>((Symbol *const &) v, s));
        }
    }
}

void SymbolDeclarationVar::addVariable(SymbolVariable *pVariable) {
    variables.push_back(pVariable);
}
