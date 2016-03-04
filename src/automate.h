//
// Created by Deirdre on 04/03/2016.
//

#ifndef LUTIN_COMPILER_AUTOMATE_H
#define LUTIN_COMPILER_AUTOMATE_H

#include <map>

typedef struct structVar {
    // What define a symbol : what it contains and if it's constant
    float value;
    bool constant;
} StructVar;

class Automate {

private:
    std::map<Symbol*, StructVar> dicoVariables;

public :

};


#endif //LUTIN_COMPILER_AUTOMATE_H
