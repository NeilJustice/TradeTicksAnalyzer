#include "pch.h"
#include "libCppUtils/Components/FloatingPoint/FloatHelper.h"
#include "libTradeTicksAnalyzer/Components/Determiners/BadTradeTicksDeterminer.h"

BadTradeTicksDeterminer::BadTradeTicksDeterminer()
   // Constant Components
   : _floatHelper(make_unique<Utils::FloatHelper>())
{
}

BadTradeTicksDeterminer::~BadTradeTicksDeterminer()
{
}

vector<TickData::TradeTick> BadTradeTicksDeterminer::FindPossibleBadTradeTicks(
   const vector<TickData::TradeTick>& /*tradeTicks*/, float /*badTickChangePercentThreshold*/) const
{
   return {};
}

// Private Functions

bool BadTradeTicksDeterminer::IsTradeTickPossiblyBad(
   const TickData::TradeTick& /*tradeTick*/, float /*badTickChangePercentThreshold*/) const
{

   return false;
}
