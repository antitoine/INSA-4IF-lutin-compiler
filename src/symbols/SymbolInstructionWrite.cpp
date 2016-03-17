//#include <boost>
#include <map>
#include "SymbolExpression.h"
#include "SymbolInstructionWrite.h"
#include "RegexSymbol.h"

using namespace std;

SymbolInstructionWrite::SymbolInstructionWrite():SymbolInstruction(S_INSTRUCTION_WRITE) {

}

void SymbolInstructionWrite::execute(map<string, StructVar*>& dicoVariables) {
    cout << symbolExpression->eval(dicoVariables) << endl;
}

Symbol *SymbolInstructionWrite::analyse(std::string &stringToAnalyse, std::string &stringSymbolDetected) {
    MatchingResult result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::ECRIRE);

    if (result.matched)
    {
        stringToAnalyse = result.stringConsumed;
        stringSymbolDetected = result.stringMatched;
        return new SymbolInstructionWrite();
    }
    else
    {
        return NULL;
    }
}

void SymbolInstructionWrite::affectExpression(SymbolExpression *expression) {
    symbolExpression = expression;
}
