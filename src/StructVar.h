#ifndef LUTIN_COMPILER_STRUCTVAR_H
#define LUTIN_COMPILER_STRUCTVAR_H

struct StructVar {
    // What define a symbol : what it contains, if it's constant, and if it has been initialized yet
    float value;
    bool constant;
    bool initialized;
};

#endif //LUTIN_COMPILER_STRUCTVAR_H
