#ifndef LUTIN_COMPILER_SYMBOL_H
#define LUTIN_COMPILER_SYMBOL_H

#include <string>
#include <list>

enum symbolIdTable {
    S_UNIT,

    S_DECLARATION,
    S_DECLARATION_CONST,
    S_DECLARATION_VAR,

    S_INSTRUCTION_AFFECT,
    S_INSTRUCTION_WRITE,
    S_INSTRUCTION_READ,

    S_VARIABLE,
    S_NUMBER,
    S_EXPRESSION_PARENTHESIS,
    S_EXPRESSION_BIN_ADD,
    S_EXPRESSION_BIN_SUB,
    S_EXPRESSION_BIN_MUL,
    S_EXPRESSION_BIN_DIV
};

enum unitSymbolIdTable {
    SU_PLUS = S_EXPRESSION_BIN_DIV + 1,
    SU_MINUS,
    SU_MULT,
    SU_DIV,
    SU_EQUAL,
    SU_AFFECT,
    SU_ENDING_PAR,
    SU_OPENNING_PAR,
    SU_COMMA,
    SU_SEMICOLON
};

enum unterminalSymbolIdTable {
    UT_P = SU_SEMICOLON + 1,
    UT_D,
    UT_D_PRIM,
    UT_V,
    UT_C,
    UT_I,
    UT_I_PRIM,
    UT_E
};


class Symbol {

protected:
    int id;

public:
    Symbol(int id) : id(id) {}
    virtual ~Symbol() {}
    virtual std::string toString();
    virtual void computeSublistSymbols(const std::list<Symbol*> & symbolsToCompute);
    operator int() const { return id; }

    int getId() const;

};

#endif //LUTIN_COMPILER_SYMBOL_H
