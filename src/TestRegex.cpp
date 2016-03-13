#include <string>
#include <iostream>
#include <re2/re2.h>
#include <assert.h>
#include "TestRegex.h"
#include "symbols/RegexSymbol.h"


void testRegex() {
    using namespace std;
    cout << "Matches : " << RegexSymbol::matches("var ab", Regex::Symbol::VAR).matched << endl;
    string foo = "var ab";
    string res = RegexSymbol::matches(foo, Regex::Symbol::VAR).stringConsumed;
    cout << "Advanced : " << res << endl;
}

void testRegexOld() {

    RE2 REG_VAR("^(var )");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_VAR !" << std::endl;
    }
    RE2 REG_CONST("^(const )");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_CONST !" << std::endl;
    }
    RE2 REG_LIRE("^(lire )");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_LIRE !" << std::endl;
    }
    RE2 REG_ECRIRE("^(ecrire )");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_ECRIRE !" << std::endl;
    }
    RE2 REG_IDENTIFICATEUR("(^[a-zA-Z](\\w)*)");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_IDENTIFICATEUR !" << std::endl;
    }
    RE2 REG_FIN_INSTRUCTION("^(;)$");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_FIN_INSTRUCTION !" << std::endl;
    }
    RE2 REG_NOMBRE("^(-?\\d+(\\.\\d*)?)");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_NOMBRE !" << std::endl;
    }
    RE2 REG_OP_PLUS("^(\\+)");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_OP_PLUS !" << std::endl;
    }
    RE2 REG_OP_MOINS("^(\\-)");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_OP_MOINS !" << std::endl;
    }
    RE2 REG_OP_DIVISER("^(\\\\)");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_OP_DIVISER !" << std::endl;
    }
    RE2 REG_OP_MULTIPLIER("^(\\*)");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_OP_MULTIPLIER !" << std::endl;
    }
    RE2 REG_OP_AFFECTER("^(:=)");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_OP_AFFECTER !" << std::endl;
    }
    RE2 REG_OP_DECLARER("^(=)");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_OP_DECLARER !" << std::endl;
    }
    RE2 REG_PARENTHESE_OUVRANTE("^(\\()");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_PARENTHESE_OUVRANTE !" << std::endl;
    }
    RE2 REG_PARENTHESE_FERMANTE("^(\\))");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_PARENTHESE_FERMANTE !" << std::endl;
    }
    RE2 REG_SEPARATEUR_DECLARATION("^(,)");
    if(!REG_VAR.ok()) {
        std::cerr << "Problem initializing REG_SEPARATEUR_DECLARATION !" << std::endl;
    }

    std::string captured;
    RE2::PartialMatch("1re2;", REG_IDENTIFICATEUR, &captured);
    std::cout << captured << std::endl;

    assert(RE2::FullMatch("hello", "h.*o"));
    assert(!RE2::FullMatch("hello", "e"));

    std::string text[] = { "While", "I", "pondered,", "weak", "and", "weary" };

    for(int i = 0; i < 6; i++) {
        re2::StringPiece result;
        if(RE2::PartialMatch(text[i], "([aeiou])", &result))
            std::cout << "First lower-case vowel at " << result.data() - text[i].data() << " & " << result.data() << " - " << text[i].data() << " -- " << result.length() << "\n";
        else
            std::cout << "No lower-case vowel\n";
    }

}
