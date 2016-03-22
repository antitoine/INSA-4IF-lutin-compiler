#if ! defined ( SYMBOLINSTRUCTIONWWRITE )
#define SYMBOLINSTRUCTIONWWRITE

#include "SymbolInstruction.h"

class SymbolInstructionWrite : public SymbolInstruction
{
public:
    SymbolInstructionWrite();
    virtual ~SymbolInstructionWrite();

    virtual std::string toString() const;
    void execute(map<string, StructVar*>& dicoVariables);
    static Symbol * analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected);
    virtual void affectExpression(SymbolExpression * expression);
    virtual void check(map<string, StructVar*>& dicoVariables);

protected:
    SymbolExpression* symbolExpression;
};

#endif
