#pragma once
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeAArgsParser.h"

class ProgramModeAArgsParserMock : public Metal::Mock<ProgramModeAArgsParser>
{
public:
   METALMOCK_NONVOID1_CONST(TradeTicksAnalyzerArgs, ParseDocoptArgs, const Time::DocoptMapType&)
};
