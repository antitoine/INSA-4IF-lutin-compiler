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

/**
 * Abstract class representing a lexical symbol.
 */
class Symbol {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    /**
     * Constructor.
     * @param Symbol's id.
     * @seealso symbolIdTable, TypeSymbolUnit, TypeSymbolUnterminal
     */
    Symbol(int id);

    /**
     * Virtual destructor.
     */
    virtual ~Symbol();

    /**
     * Return true if the symbol is persistent and can't be immediately deleted in memory. False by default.
     */
    virtual bool isPersistent() const;

    /**
     * Execute the action related to the symbol.
     * @param dicoVariables The map with the variables' status used by the program.
     */
    virtual void execute(map<string, StructVar *> &dicoVariables);

    /**
     * Check if the symbol is correct. Throw an exception if an error (or warning) is discovered.
     * @param dicoVariables The map with the variables' status used by the program.
     */
    virtual void check(map<string, StructVar *> &dicoVariables);

    /**
     * Try to optimize the current symbol.
     * @param dicoVariables The map with the variables' status used by the program.
     */
    virtual Symbol *optimize(map<string, StructVar *> &dicoVariables);

    /**
     * @return The line where the symbol was read.
     */
    virtual int getNumLineDetection() const;

    /**
     * @return The character column where the symbol was read.
     */
    virtual int getNumCharDetection() const;

    /**
     * Set the symbol's location in the file analyzed.
     */
    virtual void setSymbolDetectionPosition(int numLine, int numChar);

    /**
     * Abstract method : Convert the symbol as string.
     * @return The string describing the symbol.
     */
    virtual string toString() const = 0;

    /**
     * @return The symbol's id.
     */
    int getId() const;

    /**
     * Convert the symbol as int, by returning its id.
     */
    operator int() const { return id; }

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
protected:
    /** Id of the symbol. */
    int id;

    /** Line where the symbol was read. */
    int numLineDetection;

    /** Character column where the symbol was read. */
    int numCharDetection;
};

#endif //LUTIN_COMPILER_SYMBOL_H
