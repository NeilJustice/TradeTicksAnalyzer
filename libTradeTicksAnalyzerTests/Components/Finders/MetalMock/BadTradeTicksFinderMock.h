#pragma once
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"

class BadTradeTicksFinderMock : public Metal::Mock<BadTradeTicksFinder>
{
public:
   METALMOCK_VOID2(Initialize, const TradeTicksAnalyzerArgs&, const Utils::Logger*)
   // Actions
   METALMOCK_VOID2_CONST(FindAllPossibleBadTradeTicks,
      const fs::path&,
      bool)
};
