#include <ostream>
#include <iostream>
#include <fstream>
#include <list>
#include "automaton.h"
#include "Lexer.h"
#include "states/state0.h"
#include "symbols/SymbolDeclarationVar.h"
#include "symbols/SymbolVariable.h"
#include "symbols/SymbolNumber.h"
#include "symbols/SymbolDeclarationConst.h"
#include "symbols/SymbolExpressionBinary.h"
#include "symbols/SymbolExpressionParenthesis.h"
#include "symbols/SymbolInstruction.h"

using namespace std;

void Automaton::init() {
    // TODO
    stackStates.push(new State0());
}

int Automaton::readFile(std::string filename) {

    init();

    std::string line;
    std::ifstream file(filename);
    Symbol * symbol;

    if (!file.is_open())
    {
        std::cerr << "Error: unable to open the file " << filename << std::endl;
        return 1;
    }

    std::cout << "File " << filename << " opened." << std::endl;

    // TODO : line too long
    while (std::getline(file, line))
    {
        std::string stringToCompute(line);

        while (!stringToCompute.empty())
        {
            std::cout << "String to compute: " << stringToCompute << std::endl;
            symbol = Lexer::readNextSymbol(stringToCompute);

            if (symbol == NULL) {
                // TODO : Warning/Error : unknown symbol
                break;
            }
            else
            {
                // TODO : Compute symbol
                computeNewSymbol(symbol);
            }

        }

    }

    file.close();

    cout << "Symbols to execute, size: " << symbolsToExecute.size() << endl;
    cout << "Execute..." << endl;

    symbolsToExecute.front()->execute(dicoVariables);

    return 0;
}

void Automaton::computeNewSymbol(Symbol * symbol)
{
    stackSymbols.push(symbol);
    stackStates.top()->transition(*this, symbol);
}

void Automaton::reduction(int reductionSize, Symbol * unterminalSymbol) {

    for (int i = 0; i < reductionSize; ++i) {
        delete stackStates.top();
        stackStates.pop();
    }

    stackSymbols.push(unterminalSymbol);

    stackStates.top()->transition(*this, unterminalSymbol);
}

void Automaton::transition(Symbol * symbol, State * newState) {
    if (!stackSymbols.top()->isPersistent()) {
        delete stackSymbols.top();
    }

    stackSymbols.pop();

    stackStates.push(newState);
    if (!stackSymbols.empty()) {
        stackStates.top()->transition(*this, stackSymbols.top());
    }
}

void Automaton::accept() {
    // TODO implementer
}

void Automaton::setCurrentDeclarationVar(SymbolDeclarationVar * symbolDeclarationVar) {
    currentSymbolDeclarationVar = symbolDeclarationVar;
    symbolsToExecute.push_back(currentSymbolDeclarationVar);
    cout << "#TRACE: setCurrentDeclarationVar" << endl;
}

void Automaton::addVariableToCurrentDeclarationVar(SymbolVariable * variable) {
    if (currentSymbolDeclarationVar != NULL) {
        currentSymbolDeclarationVar->addVariable(variable);
        cout << "#TRACE: Variable " << variable->getName() << " added to the current declaration var" << endl;
    }
}

void Automaton::setCurrentDeclarationConst(SymbolDeclarationConst * symbolDeclarationConst) {
    currentSymbolDeclarationConst = symbolDeclarationConst;
    symbolsToExecute.push_back(currentSymbolDeclarationConst);
    cout << "#TRACE: setCurrentDeclarationConst" << endl;
}

void Automaton::addConstantToCurrentDeclarationConst(SymbolVariable * variable) {
    if (currentSymbolDeclarationConst != NULL) {
        currentSymbolDeclarationConst->addConstant(variable);
        cout << "#TRACE: Variable " << variable->getName() << " added to the current declaration const" << endl;
    }
}
void Automaton::addConstantValueToCurrentDeclarationConst(SymbolNumber * number) {
    if (currentSymbolDeclarationConst != NULL) {
        float constantValue = number->getFloatValue();
        currentSymbolDeclarationConst->addConstantValue(constantValue);
        cout << "#TRACE: Constant value " << constantValue << " added to the current declaration const" << endl;
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
    }
}
