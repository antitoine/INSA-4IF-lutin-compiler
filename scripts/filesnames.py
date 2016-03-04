# coding: utf-8 

import os.path


nomsSymboles = ["UnitSymbol", "SymbolInstruction", "SymbolDeclaration", "SymbolInstructionwWrite", "SymbolInstructionAffect", "SymbolDeclarationVar", "SymbolDeclarationConst", "SymbolExpression", "SymbolInstructionRead", "SymbolExpressionBinary", "SymbolExpressionParenthesis", "SymbolNumber", "SymbolVariable", "SymbolExpressionBinaryAdd", "SymbolExpressionBinarySoustract", "SymbolExpressionBinaryMultiplication", "SymbolExpressionBinaryDivision" ]
chemin = "../src/"

for symb in nomsSymboles:
	
	if not os.path.isfile(chemin+str(symb)+".h"): 
		with open(chemin+str(symb)+".h","w") as f:
			#on ecrit le .h
			texte = "#if ! defined ( "+str(symb.upper())+" ) \n"
			texte += "#define "+str(symb.upper())+" \n\n"
			
			texte += "class "+str(symb)+"\n{\n"
			texte += "public:\n"
			texte += "    "+str(symb)+"();\n\n"
			texte += "protected:\n\n};\n\n#endif\n"
			 
			f.write(texte)
	else:
		print(chemin+str(symb)+".h"+ " file already existing") 
		
	if not os.path.isfile(chemin+str(symb)+".cpp"):
		with open(chemin+str(symb)+".cpp", "w") as f:
			#on ecrit le .cpp
			texte = "#include <boost>\n"
			texte += "#include <map>\n"
			texte += "#include \""+str(symb)+".h\"\n\n"
			texte += "using namespace std;\n\n"
			texte += str(symb)+"::"+str(symb)+"()\n{\n\n}\n	"
			
			f.write(texte)
	else:
		print(chemin+str(symb)+".cpp" + " file already existing") 
		
	
