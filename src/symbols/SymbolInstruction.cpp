//#include <boost>
#include "SymbolInstruction.h"

using namespace std;

SymbolInstruction::SymbolInstruction(enum symbolIdTable idSymbol):Symbol(idSymbol)
{

}


bool SymbolInstruction::isPersistent() const {
    return true;
}