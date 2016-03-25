#ifndef LUTIN_COMPILER_REGEXLUTIN_H
#define LUTIN_COMPILER_REGEXLUTIN_H

#include <re2/re2.h>

namespace Regex {
    enum Symbol {
        VAR = 0,
        CONST,
        LIRE,
        ECRIRE,
        IDENTIFICATEUR,
        FIN_INSTRUCTION,
        NOMBRE,
        OP_PLUS,
        OP_MOINS,
        OP_DIVISER,
        OP_MULTIPLIER,
        OP_AFFECTER,
        OP_DECLARER,
        PARENTHESE_OUVRANTE,
        PARENTHESE_FERMANTE,
        SEPARATEUR_DECLARATION,
        UNKNOWN_SYMBOL
    };
}

typedef struct MatchingResult {
    bool matched;
    std::string stringMatched;
    std::string stringConsumed;
} MatchingResult;

static const RE2 REG_VAR("^( *var *)");
static const RE2 REG_CONST("^( *const *)");
static const RE2 REG_LIRE("^( *lire *)");
static const RE2 REG_ECRIRE("^( *ecrire *)");
static const RE2 REG_IDENTIFICATEUR("(^ *[a-zA-Z](\\w)* *)");
static const RE2 REG_FIN_INSTRUCTION("^( *; *)");
static const RE2 REG_NOMBRE("^( *-?\\d+(\\.\\d*)? *)");
static const RE2 REG_OP_PLUS("^( *\\+ *)");
static const RE2 REG_OP_MOINS("^( *\\- *)");
static const RE2 REG_OP_DIVISER("^( */ *)");
static const RE2 REG_OP_MULTIPLIER("^( *\\* *)");
static const RE2 REG_OP_AFFECTER("^( *:= *)");
static const RE2 REG_OP_DECLARER("^( *= *)");
static const RE2 REG_PARENTHESE_OUVRANTE("^( *\\( *)");
static const RE2 REG_PARENTHESE_FERMANTE("^( *\\) *)");
static const RE2 REG_SEPARATEUR_DECLARATION("^( *, *)");
static const RE2 REG_UNKNOWN_SYMBOL("^( *[^a-zA-Z0-9\\.\\+\\*\\-\\(\\);,/=]+ *)");

class RegexSymbol {
public:
    static MatchingResult matches(const std::string & stringToMatch, const Regex::Symbol regexToMatch);

private:
    RegexSymbol() {};
    static const RE2 * findRegex(Regex::Symbol regexToFind);

private:
    static std::map<Regex::Symbol, const RE2*> regexes;
};

#endif //LUTIN_COMPILER_REGEXLUTIN_H
