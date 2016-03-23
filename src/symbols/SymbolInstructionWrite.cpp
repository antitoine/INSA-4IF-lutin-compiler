#include <map>
#include <sstream>
#include "SymbolExpression.h"
#include "SymbolInstructionWrite.h"
#include "RegexSymbol.h"
#include "../exceptions/ErrorComposite.h"

using namespace std;

SymbolInstructionWrite::SymbolInstructionWrite():SymbolInstruction(S_INSTRUCTION_WRITE) {

}

string SymbolInstructionWrite::toString() const {
    stringstream s;
    s << "ecrire ";
    if (symbolExpression != NULL) {
        s << symbolExpression->toString();
    }
    s << ";" << endl;
    return s.str();
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

void SymbolInstructionWrite::check(map<string, StructVar *> &dicoVariables) {
    // Check the expression
    std::list<Error*> * exprErrors = symbolExpression->checkEval(dicoVariables);
    if (exprErrors != NULL) {
        throw ErrorComposite(exprErrors);
    }
}

SymbolInstructionWrite::~SymbolInstructionWrite() {
    if (symbolExpression != NULL) {
        delete symbolExpression;
    }
}

Symbol * SymbolInstructionWrite::optimize(map<string, StructVar*>& dicoVariables) {
    symbolExpression = symbolExpression->optimizeExpression(dicoVariables);
    return this;
}
