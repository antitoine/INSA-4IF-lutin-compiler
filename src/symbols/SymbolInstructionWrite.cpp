//#include <boost>
#include <map>
#include "SymbolInstructionWrite.h"
#include "RegexSymbol.h"

using namespace std;

SymbolInstructionWrite::SymbolInstructionWrite():SymbolInstruction(S_INSTRUCTION_WRITE) {

}

void SymbolInstructionWrite::execute(std::map<Symbol*, StructVar> & dicoVariables) {
    cout << symbolExpression->eval(dicoVariables) << endl;
}

Symbol *SymbolInstructionWrite::analyse(std::string &stringToAnalyse, std::string &stringSymbolDetected) {
    MatchingResult result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::CONST);

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
