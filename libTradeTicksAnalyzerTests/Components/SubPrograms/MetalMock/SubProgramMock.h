#pragma once
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"

class SubProgramMock : public Metal::Mock<SubProgram>
{
public:
   METALMOCK_VOID1(Initialize, const TradeTicksAnalyzerArgs&)
   METALMOCK_VOID0(DerivedInitialize)
   METALMOCK_NONVOID0_CONST(int, Run)
};
