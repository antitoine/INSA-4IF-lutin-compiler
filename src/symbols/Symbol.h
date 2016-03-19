#ifndef LUTIN_COMPILER_SYMBOL_H
#define LUTIN_COMPILER_SYMBOL_H

#include <string>
#include <list>
#include <map>
#include "../StructVar.h"

using namespace std;

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

enum TypeSymbolUnit {
    SYMBOL_UNIT_PLUS = S_EXPRESSION_BIN_DIV + 1,
    SYMBOL_UNIT_MINUS,
    SYMBOL_UNIT_MULT,
    SYMBOL_UNIT_DIV,
    SYMBOL_UNIT_EQUAL,
    SYMBOL_UNIT_AFFECT,
    SYMBOL_UNIT_ENDING_PAR,
    SYMBOL_UNIT_OPENING_PAR,
    SYMBOL_UNIT_COMMA,
    SYMBOL_UNIT_SEMICOLON,
    SYMBOL_UNIT_DOLLAR
};

enum TypeSymbolUnterminal {
    SYMBOL_UNTERMINAL_P = SYMBOL_UNIT_SEMICOLON + 1,
    SYMBOL_UNTERMINAL_D,
    SYMBOL_UNTERMINAL_D_PRIM,
    SYMBOL_UNTERMINAL_V,
    SYMBOL_UNTERMINAL_C,
    SYMBOL_UNTERMINAL_I,
    SYMBOL_UNTERMINAL_I_PRIM,
    SYMBOL_UNTERMINAL_E
};


class Symbol {

protected:
    int id;

public:
    Symbol(int id);
    virtual ~Symbol() {}
    virtual std::string toString() const = 0;
    operator int() const { return id; }

    virtual bool isPersistent() const;
    virtual void execute(map<string, StructVar*>& dicoVariables);
    virtual void check(map<string, StructVar*>& dicoVariables);

    int getId() const;

};

#endif //LUTIN_COMPILER_SYMBOL_H
