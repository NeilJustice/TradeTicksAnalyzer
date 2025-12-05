#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Determiners/BadTradeTicksDeterminer.h"

BadTradeTicksDeterminer::BadTradeTicksDeterminer()
{
}

BadTradeTicksDeterminer::~BadTradeTicksDeterminer()
{
}

bool BadTradeTicksDeterminer::IsTradeTickPossiblyBad(
   const TickData::TradeTick& /*tradeTick*/, float /*badTickChangePercentThreshold*/) const
{
   return false;
}
