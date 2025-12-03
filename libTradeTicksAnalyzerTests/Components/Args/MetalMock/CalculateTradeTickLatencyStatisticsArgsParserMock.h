#pragma once
#include "libTradeTicksAnalyzer/Components/Args/CalculateTradeTickLatencyStatisticsArgsParser.h"

class CalculateTradeTickLatencyStatisticsArgsParserMock : public Metal::Mock<CalculateTradeTickLatencyStatisticsArgsParser>
{
public:
   METALMOCK_NONVOID1_CONST(TradeTicksAnalyzerArgs, ParseDocoptArgs, const Time::DocoptMapType&)
};
