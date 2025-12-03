#pragma once

enum struct ProgramMode
{
   Unset,
   CalculateTradeTickLatencyStatistics,
   FindPossibleBadTradeTicks,
   Invalid,
   MaxValue
};

BEGIN_ENUM_STRING_ARRAY(ProgramMode)
ENUM_STRING_ARRAY_ELEMENT(Unset)
ENUM_STRING_ARRAY_ELEMENT(CalculateTradeTickLatencyStatistics)
ENUM_STRING_ARRAY_ELEMENT(FindPossibleBadTradeTicks)
ENUM_STRING_ARRAY_ELEMENT(Invalid)
ENUM_STRING_ARRAY_ELEMENT(MaxValue)
END_ENUM_STRING_ARRAY

ostream& operator<<(ostream& os, ProgramMode programMode);