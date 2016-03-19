#include <map>
#include <iostream>
#include <regex>
#include "SymbolVariable.h"
#include "RegexSymbol.h"
#include "../exceptions/ErrorSemanticVarIsConst.h"
#include "../exceptions/ErrorSemanticVarNotDeclared.h"
#include "../exceptions/ErrorSemanticVarNotInitialized.h"
#include "../exceptions/ErrorSemanticVarNotUsed.h"



SymbolVariable::SymbolVariable(std::string varName)
        : SymbolExpression(S_VARIABLE), name(varName), evalIsAlreadyChecked(false), constErrorIsAlreadyThrown(false), isUsed(false)
{

}

std::string SymbolVariable::toString() const {
    return name;
}

Symbol * SymbolVariable::analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected, map<string, StructVar*>& dicoVariables) {
    MatchingResult result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::IDENTIFICATEUR);

    if (result.matched)
    {
        stringToAnalyse = result.stringConsumed;
        stringSymbolDetected = result.stringMatched;

        map<string, StructVar *>::iterator it = dicoVariables.find(result.stringMatched);
        if (it != dicoVariables.end()) { // The variable exists
            return it->second->ptSymbol;
        } else {
            // Trim the name
            string varName = result.stringMatched;
            size_t first = varName.find_first_not_of(' ');
            size_t last = varName.find_last_not_of(' ');
            return new SymbolVariable(varName.substr(first, (last-first+1)));
        }
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
    map<string, StructVar*>::iterator it = dicoVariables.find(name);

    //if the variable has already been initialized
    if(it->second->isInitialized == true){
        return it->second->value;
    }
    else {
        std::cout << "Variable " << this->getName() << "has not been declared" << std::endl;
    }
}

void SymbolVariable::check(map<string, StructVar*>& dicoVariables) {
    check(dicoVariables, false);
}

void SymbolVariable::check(map<string, StructVar *> &dicoVariables, bool checkConstantUpdate) {
    // Not an eval check: check if the variable is declared
    map<string, StructVar*>::iterator it = dicoVariables.find(name);
    if (it == dicoVariables.end()) {
        throw ErrorSemanticVarNotDeclared(name);
    } else {
        if (!constErrorIsAlreadyThrown && checkConstantUpdate && it->second->isConstant) {
            constErrorIsAlreadyThrown = true;
            throw ErrorSemanticVarIsConst(name);
        }
    }

}

list<Error *> *SymbolVariable::checkEval(map<string, StructVar*>& dicoVariables) {
    if (evalIsAlreadyChecked) {
        return NULL;
    }

    std::list<Error *> * errors = NULL;

    // Check if the variable is declared
    map<string, StructVar*>::iterator it = dicoVariables.find(name);
    if (it == dicoVariables.end()) {
        errors = new list<Error *>;
        errors->push_back(new ErrorSemanticVarNotDeclared(name));
    } else {
        // Check if the variable is initialized
        if (!it->second->isInitialized) {
            errors = new list<Error *>;
            errors->push_back(new ErrorSemanticVarNotInitialized(name));
        }
    }

    evalIsAlreadyChecked = true;

    // If there is no error the variable is used correctly
    if (errors == NULL) {
        setUsed();
    }

    return errors;
}


void SymbolVariable::initCheck() {
    evalIsAlreadyChecked = false;
    isUsed = false;
}

void SymbolVariable::setUsed() {
    isUsed = true;
}

void SymbolVariable::checkUsed() {
    if (!isUsed) {
        throw ErrorSemanticVarNotUsed(name);
    }
}
