#ifndef LUTIN_COMPILER_STRUCTVAR_H
#define LUTIN_COMPILER_STRUCTVAR_H

/**
 * Struct used for describe the state of a variable, when a program is executed or checked.
 */
struct StructVar {
    /**
     * Current value of the variable.
     */
    float value;

    /**
     * True if the variable is a constant, false otherwise.
     */
    bool isConstant;

    /**
     * True if the variable have been initialized, false otherwise.
     */
    bool isInitialized;

    /**
     * True if the variable have been used in an instruction, false otherwise.
     */
    bool isUsed;
};

#endif //LUTIN_COMPILER_STRUCTVAR_H
