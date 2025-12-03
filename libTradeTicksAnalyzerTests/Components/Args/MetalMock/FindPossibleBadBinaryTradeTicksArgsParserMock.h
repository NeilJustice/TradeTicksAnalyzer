#pragma once
#include "libTradeTicksAnalyzer/Components/Args/FindPossibleBadBinaryTradeTicksArgsParser.h"

class FindPossibleBadBinaryTradeTicksArgsParserMock : public Metal::Mock<FindPossibleBadBinaryTradeTicksArgsParser>
{
public:
   METALMOCK_NONVOID1_CONST(TradeTicksAnalyzerArgs, ParseDocoptArgs, const Time::DocoptMapType&)
};
