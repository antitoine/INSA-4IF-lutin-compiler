#include <map>
#include <iostream>
#include <regex>
#include "SymbolVariable.h"
#include "SymbolNumber.h"
#include "RegexSymbol.h"
#include "../exceptions/ErrorSemanticVarIsConst.h"
#include "../exceptions/ErrorSemanticVarNotDeclared.h"
#include "../exceptions/ErrorSemanticVarNotInitialized.h"
#include "../exceptions/ErrorSemanticVarNotUsed.h"

SymbolVariable::SymbolVariable(std::string varName)
        : SymbolExpression(S_VARIABLE), name(varName)
{
}

std::string SymbolVariable::toString() const {
    return name;
}

Symbol * SymbolVariable::analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected) {
    MatchingResult result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::IDENTIFICATEUR);

    if (result.matched)
    {
        stringToAnalyse = result.stringConsumed;
        stringSymbolDetected = result.stringMatched;

        // Trim the name
        string varName = result.stringMatched;
        size_t first = varName.find_first_not_of(' ');
        size_t last = varName.find_last_not_of(' ');
        varName = varName.substr(first, (last-first+1));

        return new SymbolVariable(varName);
    }
    else
    {
        return NULL;
    }
}

std::string SymbolVariable::getName() const {
    return name;
}

float SymbolVariable::eval(map<string, StructVar*>& dicoVariables){
    // Variable already checked
    return dicoVariables[name]->value;
}

void SymbolVariable::check(map<string, StructVar*>& dicoVariables) {
    check(dicoVariables, false);
}

void SymbolVariable::check(map<string, StructVar *> &dicoVariables, bool checkConstantUpdate) {
    // Not an eval check: check if the variable is declared
    map<string, StructVar*>::iterator it = dicoVariables.find(name);
    if (it == dicoVariables.end()) {
        throw ErrorSemanticVarNotDeclared(name, numLineDetection, numCharDetection);
    } else {
        if (checkConstantUpdate && it->second->isConstant) {
            throw ErrorSemanticVarIsConst(name, numLineDetection, numCharDetection);
        }
    }
}

list<Error *> *SymbolVariable::checkEval(map<string, StructVar*>& dicoVariables) {
    std::list<Error *> * errors = NULL;

    // Check if the variable is declared
    map<string, StructVar*>::iterator it = dicoVariables.find(name);
    if (it == dicoVariables.end()) {
        errors = new list<Error *>;
        errors->push_back(new ErrorSemanticVarNotDeclared(name, numLineDetection, numCharDetection));
    } else {
        // Set variable as used
        it->second->isUsed = true;

        // Check if the variable is initialized
        if (!it->second->isInitialized) {
            errors = new list<Error *>;
            errors->push_back(new ErrorSemanticVarNotInitialized(name, numLineDetection, numCharDetection));
        }
    }

    return errors;
}


SymbolVariable::~SymbolVariable() {

}

SymbolExpression *SymbolVariable::optimizeExpression(map<string, StructVar *> &dicoVariables) {
    StructVar * ptS = dicoVariables[name];
    if (ptS->isConstant) {
        return new SymbolNumber(ptS->value);
    } else {
        return this;
    }
}
