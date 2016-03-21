#include <iostream>

#include <algorithm>
#include <string.h>
#include "Automaton.h"
#include "symbols/RegexSymbol.h"
#include "TestRegex.h"

void displayHowToAccessHelp();

using namespace std;

// Get a table of the arguments
char* getCmdOptions(int argc, char ** argv)
{
    char *results = new char[20];
    int pointer = 0;
    for (int i = 1 ; i < argc; i++) {
        if (argv[i][0] == '-'){
            // Memorize the different arguments in the result
            for (int j = 1; j < strlen(argv[i]); j++) {
                results[pointer] = argv[i][j];
                pointer++;
            }
        }
    }
    results[pointer] = '\0';
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
    cout << "   lut [-p][-a][-e][-o] infile" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "   When you invoke this command, it normally does preprocessing." << endl;
    cout << "   Options allows you to personnalize your utilisation of the command." << endl;
    cout << "   They can be in any order, and grouped (i.e. -pao) but must be placed before the infile." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "   -p : print the memory representation of the program, eventual errors printed on the standard error output" << endl;
    cout << "   -a : static analysis of the program, extract errors on the standard error output" << endl;
    cout << "   -e : interprete and execute each instructions of the program" << endl;
    cout << "   -o : simplification and optimisation of the program, if combined with -p only the tranformed program will be printed" << endl;
    cout << "   -h : print the help" << endl;
    cout << endl;
}

int main(int argc, char * argv[]) {

    // No argument
    if (argc <= 1) {
        displayHowToAccessHelp();
        return 1;
    }

    Automaton automaton;

    char * arguments = getCmdOptions(argc, argv);
    string filename = getCmdFile(argc, argv);

    //we check first if the user want the help before checking for anything else
    if(strchr(arguments, 'h'))
    {
        displayHelp();
        delete [] arguments;
        return 0;
    }

    if (!filename.compare("")) {
        cerr << "Error: unable to get the file path argument" << endl;
        displayHowToAccessHelp();
        delete [] arguments;
        return 1;
    }

    int errorCode = automaton.readFile(getCmdFile(argc, argv));

    if (errorCode) {
        // Error message has already been printed by automaton
        displayHowToAccessHelp();
        delete [] arguments;
        return errorCode;
    }


    if(strchr(arguments, 'p'))
    {
        cout << automaton.programmeToString() << endl;
    }
    if(strchr(arguments, 'a'))
    {
        // Static analysis of the program
        automaton.checkProgram();
    }
    if(strchr(arguments, 'e'))
    {
        errorCode = automaton.execute();
    }
    if(strchr(arguments, 'o'))
    {
        // Optimisation of the program
    }

    delete [] arguments;

    return errorCode;
}