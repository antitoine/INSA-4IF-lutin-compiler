#if ! defined ( SYMBOLINSTRUCTIONWWRITE )
#define SYMBOLINSTRUCTIONWWRITE

#include "SymbolInstruction.h"
#include "SymbolExpression.h"

class SymbolInstructionWrite : public SymbolInstruction
{
public:
    SymbolInstructionWrite();

protected:
    SymbolExpression* symbolExpression;
};

#endif
