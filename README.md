# lutin-compiler

## Presentation

Lutin-compiler is a 4th year Computer Science project at INSA de Lyon, aiming at creating an analysis automaton and an execution tool for a simplified programming language called Lutin.

## Syntax

Declare a variable : `var a, b` or `var x = 42`, constants are possible with `const v = 300`

Calculus : `a := 5+(4*b - (10/2))`

Retrieve a variable from keyboard input : `lire x`

Print a variable on screen : `ecrire maVariable`, or the result of an expression : `ecrire 3*(5-y)`

Warning : semi-colons are needed at each line ends

## Using the binary

### Options
* -p : print the memory representation of the program
* -a : static analysis of the program, extract errors on the standard error output
* -e : interprete and execute each instructions of the program
* -o : simplification and optimisation of the program
* -h : print the help

### Possible errors

    

| Error        							| Type           		| Return code  	|
| ------------- 						|:-------------:		| -----:		|
| ERROR_SEMANTIC_VAR_NOT_USED			| Semantic Warning      |    None		|
| ERROR_WRONG_ARGUMENTS					| Arguments			    |    1			|
| ERROR_FILE_NOT_FOUND					| I/O				    |    2			|
| ERROR_SEMANTIC_VAR_ALREADY_DECLARED	| Semtantic 			| 	 3		 	|
| ERROR_SEMANTIC_VAR_NOT_DECLARED		| Semantic      		|    4	 		|
| ERROR_SEMANTIC_VAR_IS_CONST			| Semantic    			|    5	 		|
| ERROR_SEMANTIC_VAR_NOT_INITIALIZED	| Semantic      		|    6	 		|
| ERROR_LEXICAL_UNKNOWN_SYMBOL			| Lexical     			|    7	 		|
| ERROR_LEXICAL_UNEXPECTED_SYMBOL		| Lexical     			|    8	 		|
| ERROR_LEXICAL_MISSING_SYMBOL			| Lexical     			|    9	 		|
| ERROR_SEMANTIC_INCORRECT_NUM_VALUE	| Semantic     			|    10	 		|
| ERROR_SEMANTIC_DIVISION_ZERO      	| Semantic     			|    11	 		|

### Current optimizations handled

Following cases are treated to accelerate the lutin code execution :
* Constant variables are turned into numbers everywhere they appear and partial computations can be made
* Multiplications by 0, or 0 divided by a number are pre-computed
* Adding 0 or substract 0 is an useless operation and should be removed
* Multiply or divide by 1 is an useless operation and should be removed
* Multiple levels of parenthesis should only be used when needed and are removed otherwise


## UML diagrams

[Class diagram](diagrams/class)
