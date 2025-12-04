#pragma once
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"

class BadTradeTicksFinderMock : public Metal::Mock<BadTradeTicksFinder>
{
public:
   METALMOCK_VOID1(Initialize, const Utils::Logger*)
};
