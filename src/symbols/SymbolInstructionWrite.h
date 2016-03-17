#if ! defined ( SYMBOLINSTRUCTIONWWRITE )
#define SYMBOLINSTRUCTIONWWRITE

#include "SymbolInstruction.h"

class SymbolInstructionWrite : public SymbolInstruction
{
public:
    SymbolInstructionWrite();
    void execute(map<string, StructVar*>& dicoVariables);

    static Symbol * analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected);

    virtual void affectExpression(SymbolExpression * expression);

protected:
    SymbolExpression* symbolExpression;
};

#endif
