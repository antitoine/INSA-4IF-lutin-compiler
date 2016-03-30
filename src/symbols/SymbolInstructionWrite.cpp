#include <map>
#include <sstream>
#include "SymbolExpression.h"
#include "SymbolInstructionWrite.h"
#include "RegexSymbol.h"
#include "../exceptions/ErrorComposite.h"

using namespace std;

SymbolInstructionWrite::SymbolInstructionWrite() : SymbolInstruction(S_INSTRUCTION_WRITE) {
    symbolExpression = NULL;
}

SymbolInstructionWrite::~SymbolInstructionWrite() {
    if (symbolExpression != NULL) {
        delete symbolExpression;
    }
}

string SymbolInstructionWrite::toString() const {
    stringstream s;

    if (symbolExpression == NULL) {
        return "ecrire";
    }

    s << "ecrire " << symbolExpression->toString() << ";" << endl;
    return s.str();
}

void SymbolInstructionWrite::execute(map<string, StructVar *> &dicoVariables) {
    cout << symbolExpression->eval(dicoVariables) << endl;
}

Symbol *SymbolInstructionWrite::analyse(string &stringToAnalyse, string &stringSymbolDetected) {
    MatchingResult result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::ECRIRE);

    if (result.matched) {
        stringToAnalyse = result.stringConsumed;
        stringSymbolDetected = result.stringMatched;
        return new SymbolInstructionWrite();
    } else {
        return NULL;
    }
}

void SymbolInstructionWrite::affectExpression(SymbolExpression *expression) {
    symbolExpression = expression;
}

void SymbolInstructionWrite::check(map<string, StructVar *> &dicoVariables) {
    // Check the expression
    list < Error * > *exprErrors = symbolExpression->checkEval(dicoVariables);
    if (exprErrors != NULL) {
        throw ErrorComposite(exprErrors);
    }
}

Symbol *SymbolInstructionWrite::optimize(map<string, StructVar *> &dicoVariables) {
    symbolExpression = symbolExpression->optimizeExpression(dicoVariables);
    return this;
}
