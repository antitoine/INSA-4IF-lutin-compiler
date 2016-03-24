#if ! defined ( SYMBOLVARIABLE )
#define SYMBOLVARIABLE

#include "SymbolExpression.h"
#include "../StructVar.h"

struct Pos {
    int linePos;
    int charPos;
};

class SymbolVariable : public SymbolExpression
{
public:
    SymbolVariable(std::string varName);
    virtual ~SymbolVariable();

    virtual std::string toString() const;
    static Symbol * analyse(std::string & stringToAnalyse, std::string & stringSymbolDetected);
    std::string getName() const;
    float eval(map<string, StructVar*>& dicoVariables);
    virtual void check(map<string, StructVar*>& dicoVariables); // Don't use the default value for inheritance
    virtual void check(map<string, StructVar*>& dicoVariables, bool checkConstantUpdate);
    virtual list<Error*> * checkEval(map<string, StructVar*>& dicoVariables);

    virtual SymbolExpression * optimizeExpression(map<string, StructVar*>& dicoVariables);

protected:
    std::string name;
};

#endif
