#if ! defined ( SYMBOLINSTRUCTIONREAD )
#define SYMBOLINSTRUCTIONREAD

#include "SymbolInstruction.h"
#include "SymbolVariable.h"

class SymbolInstructionRead : public SymbolInstruction
{
public:
    SymbolInstructionRead();
    void execute(std::map<Symbol*, StructVar> & dicoVariables);

protected:
    SymbolVariable* symbolVariable;
};

#endif
