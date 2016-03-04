#include
#include "Automaton.h"

using namespace std;

bool Automaton::readFile(string filename) {
    string line;
    ifstream file(filename);

    if (!myfile.is_open())
    {
        cerr << "Error: unable to open the file " << filename << endl;
        return false;
    }

    while ( getline (myfile, line) )
    {
        cout << line << '\n';
    }

    myfile.close();
}
