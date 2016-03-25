#include <ostream>
#include <iostream>
#include <fstream>
#include <list>
#include "Automaton.h"
#include "Lexer.h"
#include "states/state0.h"
#include "symbols/Symbol.h"
#include "symbols/SymbolDeclarationVar.h"
#include "symbols/SymbolVariable.h"
#include "symbols/SymbolNumber.h"
#include "symbols/SymbolDeclarationConst.h"
#include "symbols/SymbolExpressionBinary.h"
#include "symbols/SymbolExpressionParenthesis.h"
#include "symbols/SymbolInstruction.h"
#include "exceptions/Error.h"
#include "exceptions/ErrorLexicalUnexpectedSymbol.h"
#include "exceptions/ErrorSemanticVarNotUsed.h"
#include "exceptions/ErrorLexicalMissingSymbol.h"
#include "symbols/SymbolUnit.h"

using namespace std;

void Automaton::init() {
    // TODO
    stackStates.push(new State0());
    dicoVariables.clear();
    programChecked = false;
    programCanExecute = false;
}

int Automaton::readFile(std::string filename) {

    init();

    std::string line;
    std::ifstream file(filename);
    Symbol * symbol;

    if (!file.is_open())
    {
        std::cerr << "Error: unable to open the file " << filename << std::endl;
        return TypeError::ERROR_FILE_NOT_FOUND;
    }

    currentLineError = 1, currentCharPosError = 1;
    string stringSymbolDetected;

    int returnCode = 0;

    try {

        // TODO : line too long
        while (std::getline(file, line)) {
            std::string stringToCompute(line);
            currentCharPosError = 1;

            while (!stringToCompute.empty()) {
                //std::cout << "String to compute: #" << stringToCompute << "#" << std::endl;

                try {
                    symbol = Lexer::readNextSymbol(stringToCompute,
                                                   stringSymbolDetected, currentLineError, currentCharPosError);

                    symbol->setSymbolDetectionPosition(currentLineError, currentCharPosError);
                    computeNewSymbol(symbol);
                    currentCharPosError += stringSymbolDetected.length();
                } catch (Error const& error) {
                    if (error.getLevel() == WARNING) {
                        cerr << error.toString() << endl;
                        currentCharPosError += stringSymbolDetected.length();
                        continue;
                    } else {
                        throw;
                    }
                }
            }

            currentLineError++;
        }

        // Add dollar symbol
        Symbol * endSymbol = new SymbolUnit(SYMBOL_UNIT_DOLLAR);
        endSymbol->setSymbolDetectionPosition(currentLineError, currentCharPosError);
        computeNewSymbol(endSymbol);
    } catch (Error const& error) {
        // Error level here can only be critical
        cerr << error.toString() << endl;
        returnCode = error.getNumber();
    }


    file.close();

    return returnCode;
}

void Automaton::computeNewSymbol(Symbol * symbol)
{
    stackSymbols.push(symbol);

    try {
        stackStates.top()->transition(*this, symbol);
    } catch (ErrorLexicalUnexpectedSymbol const& error) {
        computeErrorLexicalUnexpectedSymbol(error);
    } catch (ErrorLexicalMissingSymbol const& error) {
        computeErrorLexicalMissingSymbol(error);
    }
}

void Automaton::reduction(int reductionSize, Symbol * unterminalSymbol) {

    for (int i = 0; i < reductionSize; ++i) {
        delete stackStates.top();
        stackStates.pop();
    }

    stackSymbols.push(unterminalSymbol);

    try {
        stackStates.top()->transition(*this, unterminalSymbol);
    } catch (ErrorLexicalUnexpectedSymbol const& error) {
        computeErrorLexicalUnexpectedSymbol(error);
    } catch (ErrorLexicalMissingSymbol const& error) {
        computeErrorLexicalMissingSymbol(error);
    }

}

void Automaton::transition(Symbol * symbol, State * newState) {
    if (!stackSymbols.top()->isPersistent()) {
        delete stackSymbols.top();
    }
    stackSymbols.pop();

    stackStates.push(newState);
    if (!stackSymbols.empty()) {
        try {
            stackStates.top()->transition(*this, stackSymbols.top());
        } catch (ErrorLexicalUnexpectedSymbol const& error) {
            computeErrorLexicalUnexpectedSymbol(error);
        } catch (ErrorLexicalMissingSymbol const& error) {
            computeErrorLexicalMissingSymbol(error);
        }
    }
}

void Automaton::computeErrorLexicalUnexpectedSymbol(ErrorLexicalUnexpectedSymbol const &error) {
    if (error.getLevel() == WARNING) {
        cerr << error.toString() << endl;
        delete stackSymbols.top();
        stackSymbols.pop();
        if (!error.isSymbolIgnored()) {
            stackSymbols.push(error.getExpectedSymbol());
            stackStates.top()->transition(*this, error.getExpectedSymbol());
        }
    } else {
        throw;
    }
}


void Automaton::computeErrorLexicalMissingSymbol(ErrorLexicalMissingSymbol const &error) {
    if (error.getLevel() == WARNING) {
        cerr << error.toString() << endl;
        stackSymbols.push(error.getMissingSymbol());
        stackStates.top()->transition(*this, error.getMissingSymbol());
    } else {
        throw;
    }
}


void Automaton::accept() {
    while (!stackStates.empty()) {
        delete stackStates.top();
        stackStates.pop();
    }

    while (!stackSymbols.empty()) {
        delete stackSymbols.top();
        stackSymbols.pop();
    }
}

void Automaton::setCurrentDeclarationVar(SymbolDeclarationVar * symbolDeclarationVar) {
    currentSymbolDeclarationVar = symbolDeclarationVar;
    symbolsToExecute.push_back(currentSymbolDeclarationVar);
}

void Automaton::addVariableToCurrentDeclarationVar(SymbolVariable * variable) {
    if (currentSymbolDeclarationVar != NULL) {
        try {
            currentSymbolDeclarationVar->addVariable(variable, dicoVariables);
        } catch (Error const& error) {
            if (error.getLevel() == WARNING) {
                cerr << error.toString() << endl;
            } else {
                throw;
            }
        }

    }
}

void Automaton::setCurrentDeclarationConst(SymbolDeclarationConst * symbolDeclarationConst) {
    currentSymbolDeclarationConst = symbolDeclarationConst;
    symbolsToExecute.push_back(currentSymbolDeclarationConst);
}

void Automaton::addConstantToCurrentDeclarationConst(SymbolVariable * variable) {
    if (currentSymbolDeclarationConst != NULL) {
        currentSymbolDeclarationConst->addConstant(variable);
    }
}
void Automaton::addConstantValueToCurrentDeclarationConst(SymbolNumber * number) {
    if (currentSymbolDeclarationConst != NULL) {
        float constantValue = number->eval();
        currentSymbolDeclarationConst->addConstantValue(constantValue, dicoVariables);
    }
}

/**
 * Aggregate the three expressions at the top of the temporary stack as one binary operator.
 */
void Automaton::aggregateBinaryOperatorExpression() {
    if (currentExpression.size() < 3) {
        cerr << "Error: incorrect binary expression." << endl;
        return;
    }

    SymbolExpression * right = currentExpression.back();
    currentExpression.pop_back();

    SymbolExpressionBinary * binaryOperator = (SymbolExpressionBinary *) currentExpression.back();
    currentExpression.pop_back();

    SymbolExpression * left = currentExpression.back();
    currentExpression.pop_back();

    binaryOperator->setOperands(left, right);

    currentExpression.push_back(binaryOperator);
}

void Automaton::aggregateParenthesisExpression() {
    if (currentExpression.size() < 2) {
        cerr << "Error: incorrect parenthesis expression." << endl;
        return;
    }


    SymbolExpression * expression = currentExpression.back();
    currentExpression.pop_back();

    ((SymbolExpressionParenthesis*)currentExpression.back())->setExpression(expression);
}

void Automaton::addToCurrentExpression(SymbolExpression *expression) {
    currentExpression.push_back(expression);
}

void Automaton::setCurrentInstruction(SymbolInstruction * instruction) {
    currentInstruction = instruction;
    currentExpression.clear();
}

void Automaton::affectCurrentExpressionToCurrentInstruction() {
    if (currentInstruction != NULL) {
        if (currentExpression.empty() || currentExpression.size() > 1) {
            cerr << "Error: incorrect expression to affect at the current instruction." << endl;
            return;
        }
        currentInstruction->affectExpression(currentExpression.back());
        currentExpression.clear();
        symbolsToExecute.push_back(currentInstruction);
        currentInstruction = NULL;
    }
}

int Automaton::execute() {

    if (!programChecked) {
        checkProgram();
    }

    if (!programCanExecute) {
        cerr << "The program can't be executed. Correct the errors and retry." << endl;
        return -1; // TODO : code ?
    }

    try {
        for (Symbol * s: symbolsToExecute) {
            s->execute(dicoVariables);
        }
    } catch (Error const& error) {
        cerr << error.toString() << endl;
        return error.getNumber();
    }


}

string Automaton::programmeToString() const {
    string programme = "";
    for(Symbol* symbol : symbolsToExecute) {
        programme += symbol->toString();
    }

    return programme;
}

void Automaton::optimizeProgram() {
    std::list<Symbol*> optimizedSymbolsToExecute;
    std::list<SymbolDeclarationConst*> declarationsToErase;
    for (Symbol * s : symbolsToExecute) {
        try {
            if (s->getId() != S_DECLARATION_CONST)
                optimizedSymbolsToExecute.push_back(s->optimize(dicoVariables));
            else {
                declarationsToErase.push_back(((SymbolDeclarationConst*) s));
            }
        } catch (Error const& error) {
            cerr << error.toString() << endl;
        }
    }

    // Remove the const declarations in optimizedSymbolsToExecute
    for (SymbolDeclarationConst * declarationConst : declarationsToErase) {
        declarationConst->detachConstant(dicoVariables);
        optimizedSymbolsToExecute.remove(declarationConst);
        delete declarationConst;
    }

    symbolsToExecute = optimizedSymbolsToExecute;
}

void Automaton::checkProgram() {
    programCanExecute = true;

    initDicoVariables();

    for (Symbol * s : symbolsToExecute) {
        try {
            s->check(dicoVariables);
        } catch (Error const& error) {
            cerr << error.toString() << endl;
            if (error.getLevel() == ERROR) {
                programCanExecute = false;
            }
        }
    }

    // Check all the variables
    checkProgramVariablesUsed();

    programChecked = true;
}

void Automaton::initDicoVariables() {
    for (pair<string, StructVar*> entry : dicoVariables) {
        entry.second->isInitialized = false;
        entry.second->isUsed = false;
    }
}

void Automaton::checkProgramVariablesUsed() {
    for (pair<string, StructVar*> entry : dicoVariables) {
        if (!entry.second->isUsed) {
            if (!entry.second->isInitialized) {
                ErrorSemanticVarNotUsed e(entry.first, true);
                cerr << e.toString() << endl;
            } else {
                ErrorSemanticVarNotUsed e(entry.first);
                cerr << e.toString() << endl;
            }

        }
    }
}

Automaton::~Automaton() {
    for (pair<string, StructVar*> entry : dicoVariables) {
        delete entry.second;
    }

    while (!stackStates.empty()) {
        delete stackStates.top();
        stackStates.pop();
    }

    while (!stackSymbols.empty()) {
        delete stackSymbols.top();
        stackSymbols.pop();
    }

    for (Symbol *s : symbolsToExecute) {
        delete s;
    }
}

