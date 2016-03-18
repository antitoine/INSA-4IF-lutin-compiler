#include <iostream>

#include <algorithm>
#include <string.h>
#include "Automaton.h"
#include "symbols/RegexSymbol.h"
#include "TestRegex.h"

void displayHelp();

using namespace std;

// Get a table of the arguments
char* getCmdOptions(int argc, char ** argv)
{
    char *results = new char[20];
    int pointer = 0;
    for (int i = 0 ; i < argc; i++) {
        if (argv[i][0] == '-'){
            // Memorize the differents arguments in the result
            for (int j = 1; j < strlen(argv[i]); j++) {
                results[pointer] = argv[i][j];
                pointer++;
            }
        } else if(i > 1) {
            // We reached the end of args, next option is the namefile. No matter of what's next.
            break;
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

// Display the help
void displayHelp() {
    cout << "In order to access the help, please use the -h option in the commande line." << endl;
}


int main(int argc, char * argv[]) {

    // No argument
    if (argc <= 1) {
        displayHelp();
        return 1;
    }

    Automaton automaton;

    char * arguments = getCmdOptions(argc, argv);
    string filename = getCmdFile(argc, argv);

    if (filename == "") {
        cerr << "Error: unable to get the file path argument" << endl;
        return 1;
    }

    int errorCode = automaton.readFile(getCmdFile(argc, argv));

    if (errorCode) {
        // Error message has already been printed by automaton
        return 1;
    }

    if(strchr(arguments, 'h'))
    {
        cout << "NAME" <<endl;
        cout << "Lutin Compiler v0.1 by H4311 - INSA Lyon 2015-2016" << endl;
        cout << "SYNOPSIS" <<endl;
        cout << "lut [-p][-a][-e][-o] infile" <<endl;
        cout << "DESCRIPTION" <<endl;
        cout << "When you invoke this command, it normally does preprocessing." <<endl;
        cout << "Options allows you to personnalize your utilisation of the command." <<endl;
        cout << "They can be in any order, and grouped (i.e. -pao) but must be placed before the infile." <<endl;
        cout << "OPTIONS" <<endl;
        cout << "-p : print the memory representation of the program, eventual errors printed on the standard error output" <<endl;
        cout << "-a : static analysis of the program, extract errors on the standard error output" <<endl;
        cout << "-e : interprete and execute each instructions of the program" <<endl;
        cout << "-o : simplification and optimisation of the program, if combined with -p only the tranformed program will be printed" <<endl;
        cout << "-h : print the help" << endl;
    }
    if(strchr(arguments, 'p'))
    {
        cout << automaton.programmeToString();
    }
    if(strchr(arguments, 'a'))
    {
        // Static analysis of the program
    }
    if(strchr(arguments, 'e'))
    {
        automaton.execute();
    }
    if(strchr(arguments, 'o'))
    {
        // Optimisation of the program
    }

    return errorCode;
}