#include <map>
#include <ostream>
#include <iostream>
#include "SymbolDeclarationVar.h"
#include "SymbolVariable.h"
#include "RegexSymbol.h"
#include "../exceptions/ErrorSemanticVarAlreadyDeclared.h"

using namespace std;

SymbolDeclarationVar::SymbolDeclarationVar()
        :SymbolDeclaration(S_DECLARATION_VAR)
{

}

string SymbolDeclarationVar::toString() const {
    string varDeclarations = "";

    if (variables.empty()) {
        return "var";
    }

    for (SymbolVariable* symbolVariable : variables) {
        varDeclarations += "var " + symbolVariable->toString() + ";\n";
    }

    return varDeclarations;
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
    for (SymbolVariable * v : variables) {
        map<string, StructVar *>::iterator it = dicoVariables.find(v->getName());
        if (it != dicoVariables.end()) {
            StructVar * ptS = it->second;

            ptS->isInitialized = false;
            ptS->isConstant = false;
        }
    }
}

void SymbolDeclarationVar::addVariable(SymbolVariable *pVariable, map<string, StructVar*>& dicoVariables) {
    // Check if the variable doesn't already exists
    map<string, StructVar *>::iterator it = dicoVariables.find(pVariable->getName());
    if (it != dicoVariables.end()) { // The variable exists
        throw ErrorSemanticVarAlreadyDeclared(pVariable->getName(), false, pVariable->getNumLineDetection(), pVariable->getNumCharDetection());
    }

    variables.push_back(pVariable);

     // Set the StructVar in the map
    StructVar * ptS = new StructVar;
    ptS->isConstant = false;
    ptS->isInitialized = false;
    ptS->isUsed = false;
    ptS->value = 0;

    dicoVariables.insert(pair<string, StructVar*>(pVariable->getName(), ptS));
}

SymbolDeclarationVar::~SymbolDeclarationVar() {
    for (SymbolVariable * ptVar : variables) {
        delete ptVar;
    }
}
