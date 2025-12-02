#pragma once
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeDeterminer.h"

class ProgramModeDeterminerMock : public Metal::Mock<ProgramModeDeterminer>
{
public:
   METALMOCK_NONVOID1_CONST(ProgramMode, DetermineProgramMode, const TradeTicksAnalyzerArgMaps&)
};
