#pragma once
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeBArgsParser.h"

class ProgramModeBArgsParserMock : public Metal::Mock<ProgramModeBArgsParser>
{
public:
   METALMOCK_NONVOID1_CONST(TradeTicksAnalyzerArgs, ParseDocoptArgs, const Time::DocoptMapType&)
};
