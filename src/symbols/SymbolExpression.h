#if ! defined ( SYMBOLEXPRESSION )
#define SYMBOLEXPRESSION

#include <list>
#include "Symbol.h"
#include "../Automaton.h"
#include "../exceptions/Error.h"

using namespace std;

class SymbolExpression : public Symbol
{
public:
    SymbolExpression(enum symbolIdTable idSymbol);
    virtual ~SymbolExpression();

    virtual std::string toString() const = 0;
    virtual float eval(std::map<std::string, StructVar*>& dicoVariables) = 0;
    virtual bool isPersistent() const;
    virtual list<Error*> * checkEval(map<string, StructVar*>& dicoVariables) = 0;



protected:


};

#endif
