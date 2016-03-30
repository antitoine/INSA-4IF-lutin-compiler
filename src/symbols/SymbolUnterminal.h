#ifndef LUTIN_COMPILER_SYMBOLUNTERMINAL_H
#define LUTIN_COMPILER_SYMBOLUNTERMINAL_H

#include "Symbol.h"

using namespace std;

/**
 * Class representing an unterminal symbol, i.e. an artificial token generated during the lexical analysis.
 */
class SymbolUnterminal : public Symbol {
// METHODS -------------------------------------------------------------------------------------------------------------    
public:
    SymbolUnterminal(enum TypeSymbolUnterminal);

    virtual ~SymbolUnterminal();

    virtual string toString() const;
};


#endif //LUTIN_COMPILER_SYMBOLUNTERMINAL_H
