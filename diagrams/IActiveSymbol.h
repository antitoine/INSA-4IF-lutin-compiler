#ifndef LUTIN_COMPILER_IACTIVESYMBOL_H
#define LUTIN_COMPILER_IACTIVESYMBOL_H

class IActiveSymbol {
public:
    virtual void computeSymbol(Symbol & symbol) = 0;
};

#endif //LUTIN_COMPILER_IACTIVESYMBOL_H
