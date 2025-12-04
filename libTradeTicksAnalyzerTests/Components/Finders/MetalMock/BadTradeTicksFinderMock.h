#pragma once
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"

class BadTradeTicksFinderMock : public Metal::Mock<BadTradeTicksFinder>
{
public:
   METALMOCK_VOID1(Initialize, const Utils::Logger*)
   // Actions
   METALMOCK_VOID3_CONST(FindAllPossibleBadTradeTicks,
      const fs::path&,
      const fs::path&,
      bool)
};
