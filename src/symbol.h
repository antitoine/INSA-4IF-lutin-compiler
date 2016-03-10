#ifndef LUTIN_COMPILER_SYMBOL_H
#define LUTIN_COMPILER_SYMBOL_H

enum symbolIdTable {
    S_UNIT,

    S_DECLARATION_CONST,
    S_DECLARATION_VAR,

    S_INSTRUCTION_AFFECT,
    S_INSTRUCTION_WRITE,
    S_INSTRUCTION_READ,

    S_VARIABLE,
    S_NUMBER,
    S_EXPRESSION_BINARY,
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
    SU_OPENNING_PAR
};

class Symbol {

protected:
    int id;

public:
    Symbol(int id) : id(id) {}
    virtual ~Symbol() {}
    void print();
    operator int() const { return id; }

};

#endif //LUTIN_COMPILER_SYMBOL_H
