#include <map>
#include <sstream>
#include "SymbolNumber.h"
#include "RegexSymbol.h"

using namespace std;

SymbolNumber::SymbolNumber() : SymbolExpression(S_NUMBER) {

}

SymbolNumber::~SymbolNumber() {

}

SymbolNumber::SymbolNumber(string stringValue) : value(stof(stringValue)), SymbolExpression(S_NUMBER) {
}

SymbolNumber::SymbolNumber(float value) : SymbolExpression(S_NUMBER), value(value) {

}

string SymbolNumber::toString() const {
    stringstream s;
    s << value;
    return s.str();
}

float SymbolNumber::eval(map<string, StructVar *> &dicoVariables) {
    return value;
}

float SymbolNumber::eval() const {
    return value;
}

Symbol *SymbolNumber::analyse(string &stringToAnalyse, string &stringSymbolDetected) {
    MatchingResult result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::NOMBRE);

    if (result.matched) {
        stringToAnalyse = result.stringConsumed;
        stringSymbolDetected = result.stringMatched;
        return new SymbolNumber(result.stringMatched);
    } else {
        return NULL;
    }
}

list<Error *> *SymbolNumber::checkEval(map<string, StructVar *> &dicoVariables) {
    return NULL;
}



