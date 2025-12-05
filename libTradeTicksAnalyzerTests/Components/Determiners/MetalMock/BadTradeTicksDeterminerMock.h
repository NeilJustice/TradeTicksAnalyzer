#pragma once
#include "libTradeTicksAnalyzer/Components/Determiners/BadTradeTicksDeterminer.h"

class BadTradeTicksDeterminerMock : public Metal::Mock<BadTradeTicksDeterminer>
{
public:
   METALMOCK_NONVOID2_CONST(vector<TickData::TradeTick>, FindPossibleBadTradeTicks,
      const vector<TickData::TradeTick>&, float)
};
