#ifndef LUTIN_COMPILER_STRUCTVAR_H
#define LUTIN_COMPILER_STRUCTVAR_H

class SymbolVariable;

struct StructVar {
    // What define a symbol : what it contains, if it's constant, and if it has been initialized yet
    float value;
    bool isConstant;
    bool isInitialized;
    bool isUsed;
};

#endif //LUTIN_COMPILER_STRUCTVAR_H
