#ifndef LUTIN_COMPILER_AUTOMATE_H
#define LUTIN_COMPILER_AUTOMATE_H

#include <map>
#include <stack>
#include <list>
#include "states/state.h"

#include "StructVar.h"
#include "exceptions/ErrorLexicalUnexpectedSymbol.h"
#include "exceptions/ErrorLexicalMissingSymbol.h"

using namespace std;

class State;
class IActiveSymbol;
class Symbol;
class SymbolDeclarationVar;
class SymbolDeclarationConst;
class SymbolVariable;
class SymbolNumber;
class SymbolExpression;
class SymbolInstruction;

/**
 * Automaton doing grammar and lexical analysis.
 */
class Automaton {
// METHODS -------------------------------------------------------------------------------------------------------------
public:
    /*
     * Read a file and start the grammar and lexical analysis, constructing the associated states.
     * @param filename The name of the file to read
     * @return 0 if the file is correct, an error code otherwise.
     */
    int readFile(string filename);

    /*
     * Make a state transition during a lexical analysis.
     * @param symbol Symbol read
     * @param newState New state to use to continue the analysis.
     */
    void transition(Symbol * symbol, State * newState);

    /**
     * Make a state reduction during a lexical analysis.
     * @param reductionSize The size of reduction, i.e. the number of symbols to remove on the stack of symbols.
     * @param unterminalSymbol The new symbol (which is unterminal) to use for the next transition.
     */
    void reduction(int reductionSize, Symbol * unterminalSymbol);

    /**
     * Finish the analysis by cleaning temporary objects.
     */
    void accept();

    /**
     * Initialise map with variables in an initial status.
     */
    void initDicoVariables();

    /**
     * Execute the program read before if it is correct.
     * @return 0 if the program is correct and can be executed, the error code otherwise.
     */
    int execute();

    /**
     * Optimize the program read before.
     */
    void optimizeProgram();

    /**
     * Check the correctness of the program read before and write on cerr errors and warnings found.
     */
    void checkProgram();

    /**
     * Set the temporary SymbolDeclarationVar currently read by the lexical analysis.
     */
    void setCurrentDeclarationVar(SymbolDeclarationVar * symbolDeclarationVar);

    /**
     * Add the SymbolVariable passed by parameter to the temporary SymbolDeclarationVar.
     */
    void addVariableToCurrentDeclarationVar(SymbolVariable * variable);

    /**
     * Set the temporary SymbolDeclarationConst currently read by the lexical analysis.
     */
    void setCurrentDeclarationConst(SymbolDeclarationConst * symbolDeclarationConst);

    /**
     * Add the SymbolVariable passed by parameter to the temporary SymbolDeclarationConst.
     */
    void addConstantToCurrentDeclarationConst(SymbolVariable * variable);

    /**
     * Add the SymbolNumber passed by parameter to the temporary SymbolDeclarationConst.
     */
    void addConstantValueToCurrentDeclarationConst(SymbolNumber * number);

    /**
     * Set the temporary SymbolInstruction currently read by the lexical analysis.
     */
    void setCurrentInstruction(SymbolInstruction * instruction);

    /**
     * Set the temporary expression to the temporary SymbolInstruction.
     */
    void affectCurrentExpressionToCurrentInstruction();

    /**
     * Aggregate the three expressions at the top of the temporary stack of expressions as one binary operator.
     */
    void aggregateBinaryOperatorExpression();

    /**
     * Aggregate the two expressions at the top of the temporary stack of expressions as one SymbolParenthesisExpression.
     */
    void aggregateParenthesisExpression();

    /**
     * Add the expression passed by parameter to the list of temporary expressions, which can be aggregated.
     */
    void addToCurrentExpression(SymbolExpression * expression);

    /**
     * Get the program string description.
     * @return The program description.
     */
    string programmeToString() const;

    /**
     * Destructor, cleaning memory.
     */
    virtual ~Automaton();

private:
    /**
     * Compute the new symbol read in a file.
     */
    void computeNewSymbol(Symbol * symbol);

    /**
     * Initiate the automaton.
     */
    void init();

    /**
     * Check if some variables are unused by the program analyzed.
     */
    void checkProgramVariablesUsed();

    /**
     * Check the error and continue the analysis (if it's possible).
     */
    void computeErrorLexicalUnexpectedSymbol(ErrorLexicalUnexpectedSymbol const& error);

    /**
     * Check the error and continue the analysis (if it's possible).
     */
    void computeErrorLexicalMissingSymbol(ErrorLexicalMissingSymbol const& error);

// ATTRIBUTES ----------------------------------------------------------------------------------------------------------
private:
    /**
     * Map with the variables used by the program.
     * @Key : variable's name
     * @Value : pointer to a StructVar struct.
     */
    map<string, StructVar*> dicoVariables;

    /** Stack of states, used during analysis. */
    stack<State*> stackStates;

    /** Stack of symbols, used during analysis. */
    stack<Symbol*> stackSymbols;

    /** List of symbols to execute, representing the program, after the file analysis. */
    list<Symbol*> symbolsToExecute;

    /** Temporary SymbolDeclarationVar, affected during analysis. */
    SymbolDeclarationVar * currentSymbolDeclarationVar;

    /** Temporary SymbolDeclarationConst, affected during analysis. */
    SymbolDeclarationConst * currentSymbolDeclarationConst;

    /** Temporary expressions. List used to construct a final expression to associate with an instruction. */
    list<SymbolExpression*> currentExpression;

    /** Temporary instruction, currently read by lexical analysis. */
    SymbolInstruction * currentInstruction;

    /** Current line of reading in the file to analyse. */
    int currentLineError;

    /** Current character column in the file to analyse. */
    int currentCharPosError;

    /** True if the program's correctness has been checked. */
    bool programChecked;

    /** True if the program is correct and can be executed. */
    bool programCanExecute;
};


#endif //LUTIN_COMPILER_AUTOMATE_H
