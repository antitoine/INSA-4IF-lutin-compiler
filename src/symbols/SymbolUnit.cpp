#include <map>
#include <iostream>
#include "SymbolUnit.h"
#include "SymbolVariable.h"
#include "RegexSymbol.h"

using namespace std;

SymbolUnit::SymbolUnit(enum TypeSymbolUnit uSymbol): Symbol(uSymbol)
{
}

string SymbolUnit::toString() const {
    switch(id) {
        case SYMBOL_UNIT_SEMICOLON:
            return ";";
        case SYMBOL_UNIT_COMMA:
            return ", ";
        case SYMBOL_UNIT_AFFECT:
            return ":=";
        case SYMBOL_UNIT_EQUAL:
            return "=";
        case SYMBOL_UNIT_PLUS:
            return "+";
        case SYMBOL_UNIT_MINUS:
            return "-";
        case SYMBOL_UNIT_DIV:
            return "/";
        case SYMBOL_UNIT_MULT:
            return "*";
        case SYMBOL_UNIT_OPENING_PAR:
            return "(";
        case SYMBOL_UNIT_ENDING_PAR:
            return ")";
        default:
            return "";
    }
}

Symbol *SymbolUnit::analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected) {
    Symbol * unitSymbol = NULL;
    MatchingResult result;

    if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::FIN_INSTRUCTION)).matched) {
        unitSymbol = new SymbolUnit(SYMBOL_UNIT_SEMICOLON);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::SEPARATEUR_DECLARATION)).matched) {
        unitSymbol = new SymbolUnit(SYMBOL_UNIT_COMMA);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::OP_AFFECTER)).matched) {
        unitSymbol = new SymbolUnit(SYMBOL_UNIT_AFFECT);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::OP_DECLARER)).matched) {
        unitSymbol = new SymbolUnit(SYMBOL_UNIT_EQUAL);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::OP_PLUS)).matched) {
        unitSymbol = new SymbolUnit(SYMBOL_UNIT_PLUS);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::OP_MOINS)).matched) {
        unitSymbol = new SymbolUnit(SYMBOL_UNIT_MINUS);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::OP_DIVISER)).matched) {
        unitSymbol = new SymbolUnit(SYMBOL_UNIT_DIV);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::OP_MULTIPLIER)).matched) {
        unitSymbol = new SymbolUnit(SYMBOL_UNIT_MULT);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::PARENTHESE_OUVRANTE)).matched) {
        unitSymbol = new SymbolUnit(SYMBOL_UNIT_OPENING_PAR);
    } else if ((result = RegexSymbol::matches(stringToAnalyse, Regex::Symbol::PARENTHESE_FERMANTE)).matched) {
        unitSymbol = new SymbolUnit(SYMBOL_UNIT_ENDING_PAR);
    }

    if (result.matched)
    {
        stringSymbolDetected = result.stringMatched;
        stringToAnalyse = result.stringConsumed;
    }
    else
    {
        return NULL;
    }

    return unitSymbol;
}

SymbolUnit::~SymbolUnit() {

}
