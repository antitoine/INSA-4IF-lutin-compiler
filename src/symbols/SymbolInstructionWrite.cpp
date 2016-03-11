//#include <boost>
#include <map>
#include "SymbolInstructionWrite.h"

using namespace std;

SymbolInstructionWrite::SymbolInstructionWrite():SymbolInstruction(S_INSTRUCTION_WRITE) {

}

void SymbolInstructionWrite::execute(std::map<Symbol*, StructVar> & dicoVariables) {
    cout << symbolExpression->eval(dicoVariables) << endl;
}
