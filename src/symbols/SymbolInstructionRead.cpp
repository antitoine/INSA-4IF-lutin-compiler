//#include <boost>
#include <map>
#include "SymbolInstructionRead.h"
#include "RegexSymbol.h"


SymbolInstructionRead::SymbolInstructionRead():SymbolInstruction(S_INSTRUCTION_READ)
{

}

void SymbolInstructionRead::execute(map<string, StructVar*>& dicoVariables){
    float userValue;
    cout << "?" << symbolVariable->getName() << " : ";
    cout.flush();
    std::cin >> userValue;

    // We check if the variable is already in the dico
    map<string, StructVar *>::iterator it = dicoVariables.find(symbolVariable->getName());
    if (it != dicoVariables.end()) { // The variable exists
        StructVar * ptS = it->second;
        ptS->value = userValue;
        ptS->isInitialized = true;
    } else {
        // TODO : Exception
        std::cout << "Variable " << symbolVariable->getName() << "has not been declared" << std::endl;
    }
}

void SymbolInstructionRead::affectExpression(SymbolExpression *expression) {
    if (SymbolVariable * variable = dynamic_cast<SymbolVariable *>(expression)) {
        symbolVariable = variable;
    } else {
        cerr << "Error: incorrect expression for read instruction." << endl;
        // TODO : exception
    }
}

Symbol *SymbolInstructionRead::analyse(std::string &stringToAnalyse, std::string &stringSymbolDetected) {
    MatchingResult result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::LIRE);

    if (result.matched)
    {
        stringToAnalyse = result.stringConsumed;
        stringSymbolDetected = result.stringMatched;
        return new SymbolInstructionRead();
    }
    else
    {
        return NULL;
    }
}
