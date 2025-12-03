#pragma once
#include "libTradeTicksAnalyzer/Components/Args/FindPossibleBadTradeTicksArgsParser.h"

class FindPossibleBadTradeTicksArgsParserMock : public Metal::Mock<FindPossibleBadTradeTicksArgsParser>
{
public:
   METALMOCK_NONVOID1_CONST(TradeTicksAnalyzerArgs, ParseDocoptArgs, const Time::DocoptMapType&)
};
