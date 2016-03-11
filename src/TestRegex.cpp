#include <boost/regex.hpp>
#include <string>
#include <iostream>
#include "TestRegex.h"

void testRegex () {
    //boost::regex r("(st|mt)|tr");
//    cerr << "st|mt|tr" << " matches st? " << regex_match("st", r) << endl;
//    cerr << "st|mt|tr" << " matches mt? " << regex_match("mt", r) << endl;
//    cerr << "st|mt|tr" << " matches tr? " << regex_match("tr", r) << endl;


    // Regex for the project
    boost::regex REG_VAR("(var )");
    std::string var = "var ";
    boost::smatch match;
    std::cout << "Match : " << regex_match(var, match, REG_VAR);

//    regex REG_CONST("^const ");
//    regex REG_LIRE("^lire ");
//    regex REG_ECRIRE("^ecrire ");
//    regex REG_IDENTIFICATEUR("^[a-zA-Z](\\w)*");
//    regex REG_FIN_INSTRUCTION("^;$");
//    regex REG_NOMBRE("^-?\\d+(\\.\\d*)?");
//    regex REG_OP_PLUS("^\\+");
//    regex REG_OP_MOINS("^\\-");
//    regex REG_OP_DIVISER("^\\\\");
//    regex REG_OP_MULTIPLIER("^\\\\");
//    regex REG_OP_AFFECTER("^:=");
//    regex REG_OP_DECLARER("^=");
//    regex REG_PARENTHESE_OUVRANTE("^\\(");
//    regex REG_PARENTHESE_FERMANTE("^\\)");
//    regex REG_SEPARATEUR_DECLARATION("^,");

}
