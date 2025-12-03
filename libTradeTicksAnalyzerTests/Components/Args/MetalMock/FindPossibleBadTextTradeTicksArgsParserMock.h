#pragma once
#include "libTradeTicksAnalyzer/Components/Args/FindPossibleBadTextTradeTicksArgsParser.h"

class FindPossibleBadTextTradeTicksArgsParserMock : public Metal::Mock<FindPossibleBadTextTradeTicksArgsParser>
{
public:
   METALMOCK_NONVOID1_CONST(TradeTicksAnalyzerArgs, ParseDocoptArgs, const Time::DocoptMapType&)
};
