//#include <boost>
#include <map>
#include <iostream>
#include "UnitSymbol.h"
#include "SymbolVariable.h"
#include "RegexSymbol.h"

using namespace std;

UnitSymbol::UnitSymbol(enum TypeSymbolUnit uSymbol):Symbol(uSymbol)
{
}

std::string UnitSymbol::toString() {
    std::cout << "Symbol ID (id: " << id << ")" << std::endl;
}

Symbol * UnitSymbol::analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected) {
    Symbol * unitSymbol = NULL;
    MatchingResult result;

    if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::FIN_INSTRUCTION)).matched) {
        unitSymbol = new UnitSymbol(SYMBOL_UNIT_SEMICOLON);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::SEPARATEUR_DECLARATION)).matched) {
        unitSymbol = new UnitSymbol(SYMBOL_UNIT_COMMA);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::OP_AFFECTER)).matched) {
        unitSymbol = new UnitSymbol(SYMBOL_UNIT_AFFECT);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::OP_DECLARER)).matched) {
        unitSymbol = new UnitSymbol(SYMBOL_UNIT_EQUAL);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::OP_PLUS)).matched) {
        unitSymbol = new UnitSymbol(SYMBOL_UNIT_PLUS);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::OP_MOINS)).matched) {
        unitSymbol = new UnitSymbol(SYMBOL_UNIT_MINUS);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::OP_DIVISER)).matched) {
        unitSymbol = new UnitSymbol(SYMBOL_UNIT_DIV);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::OP_MULTIPLIER)).matched) {
        unitSymbol = new UnitSymbol(SYMBOL_UNIT_MULT);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::PARENTHESE_OUVRANTE)).matched) {
        unitSymbol = new UnitSymbol(SYMBOL_UNIT_OPENING_PAR);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::PARENTHESE_FERMANTE)).matched) {
        unitSymbol = new UnitSymbol(SYMBOL_UNIT_ENDING_PAR);
    }

    // TODO : other cases

    if (result.matched)
    {
        stringSymbolDetected = result.stringMatched;
        stringToAnalyse = result.stringConsumed;
    }
    else
    {
        // TODO : other cases
        return NULL;
    }

    return unitSymbol;
}
