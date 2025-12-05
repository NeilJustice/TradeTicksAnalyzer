#include "pch.h"
#include "libCppUtils/Components/FloatingPoint/FloatHelper.h"
#include "libFunctional/Components/Filters/Member/TwoArgMemberFunctionFilter.h"
#include "libTradeTicksAnalyzer/Components/Determiners/BadTradeTicksDeterminer.h"

BadTradeTicksDeterminer::BadTradeTicksDeterminer()
   // Function Callers
   : _filter_IsTradeTickPossiblyBad(make_unique<_filter_IsTradeTickPossiblyBadType>())
   // Constant Components
   , _floatHelper(make_unique<Utils::FloatHelper>())
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
