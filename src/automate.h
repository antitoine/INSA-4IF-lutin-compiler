//
// Created by Deirdre on 04/03/2016.
//

#ifndef LUTIN_COMPILER_AUTOMATE_H
#define LUTIN_COMPILER_AUTOMATE_H

#include <map>

struct structVar {
    // What define a symbol : what it contains and if it's constant
    float value;
    bool constant;
};


class Automate {

public :

private:
    map<&Symbol, structVar> librairy;


};


#endif //LUTIN_COMPILER_AUTOMATE_H
