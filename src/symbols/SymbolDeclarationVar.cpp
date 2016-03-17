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

void SymbolDeclarationVar::execute(map<string, StructVar*>& dicoVariables) {
    cout << "#TRACE: execute declaration var" << endl;
    for (SymbolVariable * v : variables) {
        map<string, StructVar *>::iterator it = dicoVariables.find(v->getName());
        if (it != dicoVariables.end()) {
            StructVar * ptS = it->second;

            ptS->ptSymbol = v;
            ptS->isInitialized = false;
            ptS->isConstant = false;
        }
    }
}

void SymbolDeclarationVar::addVariable(SymbolVariable *pVariable, map<string, StructVar*>& dicoVariables) {
    // Check if the variable doesn't already exists
    map<string, StructVar *>::iterator it = dicoVariables.find(pVariable->getName());
    if (it != dicoVariables.end()) { // The variable exists
        cerr << "Error: the variable " << pVariable->getName() << " has already been declared." << endl;
        // TODO : Exception
        return;
    }

    variables.push_back(pVariable);

     // Set the StructVar in the map
    StructVar * ptS = new StructVar;
    ptS->ptSymbol = pVariable;
    ptS->isConstant = false;
    ptS->isInitialized = false;
    ptS->value = 0;

    dicoVariables.insert(pair<string, StructVar*>(pVariable->getName(), ptS));
}
