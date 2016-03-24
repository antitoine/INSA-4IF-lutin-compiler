#include <map>
#include "SymbolInstructionRead.h"
#include "RegexSymbol.h"

using namespace std;

SymbolInstructionRead::SymbolInstructionRead():SymbolInstruction(S_INSTRUCTION_READ)
{
    symbolVariable = NULL;
}

string SymbolInstructionRead::toString() const {
    if (symbolVariable == NULL) {
        return "lire";
    }
    return "lire " + symbolVariable->toString() + ";\n";
}

void SymbolInstructionRead::execute(map<string, StructVar*>& dicoVariables){
    float userValue;
    cout << "?" << symbolVariable->getName() << " : ";
    cout.flush();
    std::cin >> userValue;

    // Instruction already checked
    dicoVariables[symbolVariable->getName()]->value = userValue;
}

void SymbolInstructionRead::affectExpression(SymbolExpression *expression) {
    symbolVariable = (SymbolVariable *) expression;
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

void SymbolInstructionRead::check(map<string, StructVar *> &dicoVariables) {
    // Check variable to affect
    symbolVariable->check(dicoVariables);

    // If the check is correct, the variable is set as initialized
    StructVar * pt = dicoVariables[symbolVariable->getName()];
    pt->isInitialized = true;

    // Set the variable as used
    pt->isUsed = true;
}

SymbolInstructionRead::~SymbolInstructionRead() {
    if (symbolVariable != NULL) {
        delete symbolVariable;
    }
}
