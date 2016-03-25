#include <iostream>

#include <algorithm>
#include <string.h>
#include "Automaton.h"
#include "symbols/RegexSymbol.h"
#include "exceptions/ErrorArgument.h"

void displayHowToAccessHelp();

using namespace std;

char ARG_HELP           = 'h';
char ARG_ANALYSIS       = 'a';
char ARG_OPTIMISATION   = 'o';
char ARG_DISPLAY_MEM    = 'p';
char ARG_EXECUTION      = 'e';

string allowedArgs = ARG_HELP + ARG_ANALYSIS + ARG_OPTIMISATION + ARG_DISPLAY_MEM + ARG_EXECUTION + "";

// Get a table of the arguments
string getCmdOptions(int argc, char ** argv)
{
    string results = "";
    for (int i = 1 ; i < argc; i++) {
        if (argv[i][0] == '-'){
            // Memorize the different arguments in the result
            for (int j = 1; j < strlen(argv[i]); j++) {
                if (allowedArgs.find(argv[i][j]) != string::npos && results.find(argv[i][j]) == string::npos) {
                    results += argv[i][j];
                } else {
                    throw ErrorArgument();
                }
            }
        }
    }
    return results;
}

// Get the filename
string getCmdFile(int argc, char ** argv)
{
    // Get the first argument after the options as filename
    for (int i = 1 ; i < argc; i++) {
        if (argv[i][0] != '-'){
            return argv[i];
        }
    }
    return "";
}

// Display how to display help
void displayHowToAccessHelp() {
    cout << "Lutin Compiler by H4311" << endl;
    cout << "In order to access the help, please use the -h option in the command line." << endl;
}

// Display help message
void displayHelp(){
    cout << "Lutin Compiler by H4311 - INSA Lyon 2015-2016 - Version 0.1" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "   lut [-" << ARG_DISPLAY_MEM << "][-" << ARG_ANALYSIS << "][-" << ARG_EXECUTION << "][-" << ARG_OPTIMISATION << "] infile" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "   When you invoke this command, it normally does preprocessing." << endl;
    cout << "   Options allows you to personnalize your utilisation of the command." << endl;
    cout << "   They can be in any order, and grouped (i.e. -pao) but must be placed before the infile." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "   -" << ARG_DISPLAY_MEM << " : print the memory representation of the program, eventual errors printed on the standard error output" << endl;
    cout << "   -" << ARG_ANALYSIS << " : static analysis of the program, extract errors on the standard error output" << endl;
    cout << "   -" << ARG_EXECUTION << " : interprete and execute each instructions of the program" << endl;
    cout << "   -" << ARG_OPTIMISATION << " : simplification and optimisation of the program, if combined with -p only the tranformed program will be printed" << endl;
    cout << "   -" << ARG_HELP << " : print the help" << endl;
    cout << endl;
}

int main(int argc, char * argv[]) {

    // No argument
    if (argc <= 1) {
        displayHowToAccessHelp();
        return TypeError::ERROR_WRONG_ARGUMENTS;
    }

    Automaton automaton;

    string arguments = "";
    string filename = "";
    try {
        arguments = getCmdOptions(argc, argv);
        filename = getCmdFile(argc, argv);
    } catch (ErrorArgument error) {
        cerr << error.toString() << endl;
        displayHowToAccessHelp();
        return TypeError::ERROR_WRONG_ARGUMENTS;
    }

    //we check first if the user want the help before checking for anything else
    if(arguments.find(ARG_HELP) != string::npos)
    {
        displayHelp();
        return 0;
    }

    if (!filename.compare("")) {
        cerr << "Error: unable to get the file path argument" << endl;
        displayHowToAccessHelp();
        return TypeError::ERROR_FILE_NOT_FOUND;
    }

    int errorCode = automaton.readFile(getCmdFile(argc, argv));

    if (errorCode) {
        // Error message has already been printed by automaton
        displayHowToAccessHelp();
        return errorCode;
    }


    if(arguments.find(ARG_OPTIMISATION) != string::npos)
    {
        // Optimisation of the program
        automaton.optimizeProgram();
    }
    if(arguments.find(ARG_ANALYSIS) != string::npos)
    {
        // Static analysis of the program
        automaton.checkProgram();
    }
    if(arguments.find(ARG_DISPLAY_MEM) != string::npos)
    {
        cout << automaton.programmeToString() << endl;
    }
    if(arguments.find(ARG_EXECUTION) != string::npos)
    {
        errorCode = automaton.execute();
    }

    return errorCode;
}