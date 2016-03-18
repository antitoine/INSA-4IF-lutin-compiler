#include <map>
#include <iostream>
#include "SymbolDeclarationConst.h"
#include "Symbol.h"
#include "RegexSymbol.h"
#include <re2/re2.h>

using namespace std;

SymbolDeclarationConst::SymbolDeclarationConst() : SymbolDeclaration(S_DECLARATION_CONST)
{

}

std::string SymbolDeclarationConst::toString() const {
    string constDeclarations = "";
    for(std::pair<SymbolVariable*, float> symbolVariable : constants) {
        constDeclarations += "const " + symbolVariable.first->toString() + " = " + to_string(symbolVariable.second) + ";\n";
    }

    return constDeclarations;
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

void SymbolDeclarationConst::execute(map<string, StructVar*>& dicoVariables) {
    //For each constant declaration, initialize the struct var
    for (auto const &v : constants) {
        StructVar * ptS = dicoVariables[v.first->getName()];

        ptS->ptSymbol = v.first;
        ptS->isInitialized = true;
        ptS->isConstant = true;
        ptS->value = v.second;
    }
}

void SymbolDeclarationConst::addConstant(SymbolVariable *pVariable) {
    temporaryPtVariable = pVariable;
}

void SymbolDeclarationConst::addConstantValue(float constantValue, map<string, StructVar*>& dicoVariables) {
    if (temporaryPtVariable != NULL) {

        // Check if the variable doesn't already exists
        map<string, StructVar *>::iterator it = dicoVariables.find(temporaryPtVariable->getName());
        if (it != dicoVariables.end()) { // The variable exists
            cerr << "Error: the variable " << temporaryPtVariable->getName() << " has already been declared." << endl;
            // TODO : Exception
            return;
        }

        constants.insert(pair<SymbolVariable*, float>(temporaryPtVariable, constantValue));

        // Set the StructVar in the map
        StructVar * ptS = new StructVar;
        ptS->ptSymbol = temporaryPtVariable;
        ptS->isConstant = true;
        ptS->isInitialized = true;
        ptS->value = constantValue;

        dicoVariables.insert(pair<string, StructVar*>(temporaryPtVariable->getName(), ptS));

        temporaryPtVariable = NULL;
    } else {
        cerr << "No constant to affect a value." << endl;
    }
}
