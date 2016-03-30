#include <iostream>
#include "RegexSymbol.h"

// To initialize the const map
std::map<Regex::Symbol, const RE2 *> RegexSymbol::regexes = {
        {Regex::Symbol::VAR,                    &REG_VAR},
        {Regex::Symbol::CONST,                  &REG_CONST},
        {Regex::Symbol::LIRE,                   &REG_LIRE},
        {Regex::Symbol::ECRIRE,                 &REG_ECRIRE},
        {Regex::Symbol::IDENTIFICATEUR,         &REG_IDENTIFICATEUR},
        {Regex::Symbol::FIN_INSTRUCTION,        &REG_FIN_INSTRUCTION},
        {Regex::Symbol::NOMBRE,                 &REG_NOMBRE},
        {Regex::Symbol::OP_PLUS,                &REG_OP_PLUS},
        {Regex::Symbol::OP_MOINS,               &REG_OP_MOINS},
        {Regex::Symbol::OP_DIVISER,             &REG_OP_DIVISER},
        {Regex::Symbol::OP_MULTIPLIER,          &REG_OP_MULTIPLIER},
        {Regex::Symbol::OP_AFFECTER,            &REG_OP_AFFECTER},
        {Regex::Symbol::OP_DECLARER,            &REG_OP_DECLARER},
        {Regex::Symbol::PARENTHESE_OUVRANTE,    &REG_PARENTHESE_OUVRANTE},
        {Regex::Symbol::PARENTHESE_FERMANTE,    &REG_PARENTHESE_FERMANTE},
        {Regex::Symbol::SEPARATEUR_DECLARATION, &REG_SEPARATEUR_DECLARATION},
        {Regex::Symbol::UNKNOWN_SYMBOL,         &REG_UNKNOWN_SYMBOL},
};

const RE2 *RegexSymbol::findRegex(Regex::Symbol regexToFind) {
    std::map<Regex::Symbol, const RE2 *>::iterator it = regexes.find(regexToFind);
    if (it != regexes.end()) {
        return it->second;
    }
    return NULL;
}

MatchingResult RegexSymbol::matches(const std::string &stringToMatch, const Regex::Symbol regexToMatch) {
    const RE2 *regex = findRegex(regexToMatch);
    if (regex != NULL) {
        re2::StringPiece result;
        if (RE2::PartialMatch(stringToMatch, *regex, &result)) {
            std::string stringConsumed = result.end();

            return MatchingResult {true, result.as_string(), stringConsumed};
        }
    }
    return MatchingResult {false, "", ""};
}

