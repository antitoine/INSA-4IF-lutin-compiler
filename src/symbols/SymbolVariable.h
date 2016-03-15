#if ! defined ( SYMBOLVARIABLE )
#define SYMBOLVARIABLE

#include "SymbolExpression.h"
#include "../StructVar.h"

class SymbolVariable : public SymbolExpression
{
public:
    SymbolVariable(std::string varName);
    virtual std::string toString();
    static Symbol * analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected);
    std::string getName() const;
    float eval(std::map<Symbol*, StructVar> & dicoVariables);


protected:

private:
    std::string name;
};

#endif
