#if ! defined ( SYMBOLINSTRUCTIONREAD )
#define SYMBOLINSTRUCTIONREAD

#include "SymbolInstruction.h"
#include "SymbolVariable.h"

class SymbolInstructionRead : public SymbolInstruction
{
public:
    SymbolInstructionRead();
    void execute(map<string, StructVar*>& dicoVariables);
    virtual std::string toString() const;
    virtual void affectExpression(SymbolExpression * expression);
    static Symbol * analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected);

    virtual void check(map<string, StructVar*>& dicoVariables);

protected:
    SymbolVariable* symbolVariable;
};

#endif
