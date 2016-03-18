#if ! defined ( SYMBOLINSTRUCTIONWWRITE )
#define SYMBOLINSTRUCTIONWWRITE

#include "SymbolInstruction.h"

class SymbolInstructionWrite : public SymbolInstruction
{
public:
    SymbolInstructionWrite();
    virtual std::string toString() const;
    void execute(map<string, StructVar*>& dicoVariables);
    static Symbol * analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected);
    virtual void affectExpression(SymbolExpression * expression);

protected:
    SymbolExpression* symbolExpression;
};

#endif
