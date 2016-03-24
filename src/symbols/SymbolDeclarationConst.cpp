#include <map>
#include <iostream>
#include <algorithm>
#include "SymbolDeclarationConst.h"
#include "Symbol.h"
#include "RegexSymbol.h"
#include "SymbolNumber.h"
#include "../exceptions/ErrorSemanticVarAlreadyDeclared.h"
#include <re2/re2.h>

using namespace std;

SymbolDeclarationConst::SymbolDeclarationConst() : SymbolDeclaration(S_DECLARATION_CONST)
{

}

string SymbolDeclarationConst::toString() const {
    string constDeclarations = "";

    if (constants.empty()) {
        return "const";
    }

    for(pair<SymbolVariable*, float> symbolVariable : constants) {
        string constValue = to_string(symbolVariable.second);
        constValue = SymbolNumber::removeLeadingZeroes(constValue);

        constDeclarations += "const " + symbolVariable.first->toString() + " = " + constValue + ";\n";
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
            throw ErrorSemanticVarAlreadyDeclared(temporaryPtVariable->getName(), true, temporaryPtVariable->getNumLineDetection(), temporaryPtVariable->getNumCharDetection());
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

void SymbolDeclarationConst::check(map<string, StructVar *> &dicoVariables) {
    for (pair<SymbolVariable *const, float> & entry : constants) {
        dicoVariables[entry.first->getName()]->isInitialized = true;
    }
}

SymbolDeclarationConst::~SymbolDeclarationConst() {
    for (pair<SymbolVariable *const, float> & entry : constants) {
        delete entry.first;
    }

}
