//#include <boost>
#include <map>
#include "SymbolNumber.h"
#include "RegexSymbol.h"

using namespace std;

SymbolNumber::SymbolNumber() : SymbolExpression(S_NUMBER) {

}

SymbolNumber::SymbolNumber(string stringValue) : value(stof(stringValue)), SymbolExpression(S_NUMBER) {
}

float SymbolNumber::eval(map<string, StructVar*>& dicoVariables){
    return value;
}

float SymbolNumber::eval() const {
    return value;
}

Symbol *SymbolNumber::analyse(std::string &stringToAnalyse, std::string &stringSymbolDetected) {
    MatchingResult result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::NOMBRE);

    if (result.matched)
    {
        stringToAnalyse = result.stringConsumed;
        stringSymbolDetected = result.stringMatched;
        return new SymbolNumber(result.stringMatched);
    }
    else
    {
        return NULL;
    }
}


