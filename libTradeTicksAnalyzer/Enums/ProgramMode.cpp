#include "pch.h"
#include "libTradeTicksAnalyzer/Enums/ProgramMode.h"

ostream& operator<<(ostream& os, ProgramMode programMode)
{
   os << ENUM_AS_STRING(ProgramMode, programMode);
   return os;
}
