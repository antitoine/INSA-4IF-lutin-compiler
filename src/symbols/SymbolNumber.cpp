//#include <boost>
#include <map>
#include "SymbolNumber.h"

using namespace std;

SymbolNumber::SymbolNumber() : SymbolExpression(S_NUMBER) {

}

float SymbolNumber::eval(std::map<Symbol*, StructVar> & dicoVariables){
    return value;
}

