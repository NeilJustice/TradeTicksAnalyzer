#pragma once
#include "libTradeTicksAnalyzer/Components/Args/TradeTicksAnalyzerArgsParser.h"

class TradeTicksAnalyzerArgsParserMock : public Metal::Mock<TradeTicksAnalyzerArgsParser>
{
public:
   METALMOCK_NONVOID1_CONST(TradeTicksAnalyzerArgs, ParseStringArgs, const vector<string>&)
};
