#pragma once
#include "libTradeTicksAnalyzerTests/Components/Testing/TradeTicksAnalyzerRandomGenerator.h"

class TradeTicksAnalyzerRandomGeneratorMock : public Metal::Mock<TradeTicksAnalyzerRandomGenerator>
{
public:
   METALMOCK_NONVOID0_CONST(ProgramMode, RandomProgramMode)
};
