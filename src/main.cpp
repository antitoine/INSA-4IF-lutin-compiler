#include <iostream>
#include <algorithm>
#include <string.h>
#include "automaton.h"
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
    cout << "Lutin Compiler v0.1 by H4311 - INSA Lyon 2015-2016" << endl;
    // TODO Print the help section
}

int main(int argc, char * argv[]) {

    if (argc <= 1) {
        displayHelp();
        return 1;
    }

    Automaton automaton;

    char * arguments = getCmdOptions(argc, argv);

    if(strchr(arguments, 'p'))
    {
        // Print Memory Structure
    }
    if(strchr(arguments, 'a'))
    {
        // Static analysis of the program
    }
    if(strchr(arguments, 'e'))
    {
        // Execution of the program
    }
    if(strchr(arguments, 'o'))
    {
        // Optimisation of the program
    }

    string filename = getCmdFile(argc, argv);
    if (filename != "")
        automaton.readFile(getCmdFile(argc, argv));
    else
        //automaton.readFile("/home/pierre/Documents/Projects/lutin-compiler/test/testTMP");

    return 0;
}