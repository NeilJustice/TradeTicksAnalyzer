#pragma once
#include "libTradeTicksAnalyzer/Components/Determiners/BadTradeTicksDeterminer.h"

class BadTradeTicksDeterminerMock : public Metal::Mock<BadTradeTicksDeterminer>
{
public:
   METALMOCK_NONVOID2_CONST(bool, IsTradeTickPossiblyBad,
      const TickData::TradeTick&, float)
};
