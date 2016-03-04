#!/bin/python

#Generate states
for stateNumber in range(0, 45):

    strState = str(stateNumber)
    f = open("../src/states/state" + strState + ".cpp", 'w')
    f.write("#include \"state" + strState + ".h\"")

    #Constructor
    f.write("\n\n")
    f.write("bool State" + strState + "::transition(")
    f.write("Automaton automaton, ")
    f.write("Symbol symbol) {\n");
    f.write("    return false;\n")
    f.write("}");

    #Transition method
    f.write("\n\n")
    f.write("State" + strState + "::State" + strState + "() {\n")
    f.write("    State(\"\");\n")
    f.write("}");
    f.close()

    #Header
    f = open("../src/states/state" + strState + ".h", 'w')
    f.write("#ifndef STATE" + strState + "_H\n")
    f.write("#define STATE" + strState + "_H\n\n")
    f.write("class State" + strState + " : public State {\n\n")
    f.write("public:\n")
    f.write("    State" + strState + "();\n")
    f.write("    ~State" + strState + "();\n")
    f.write("    bool transition(Automaton automaton, Symbol symbol);\n\n")
    f.write("};\n\n")
    f.write("#endif //STATE" + strState + "_H")

    f.close()