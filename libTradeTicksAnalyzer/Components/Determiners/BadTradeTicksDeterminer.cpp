#include "pch.h"
#include "libCppUtils/Components/FloatingPoint/FloatHelper.h"
#include "libFunctional/Components/Filters/Member/TwoArgMemberFunctionFilter.h"
#include "libTickData/Components/Determiners/TradeConditionIdentifierDeterminer.h"
#include "libTradeTicksAnalyzer/Components/Determiners/BadTradeTicksDeterminer.h"

BadTradeTicksDeterminer::BadTradeTicksDeterminer()
   // Function Callers
   : _filter_IsTradeTickPossiblyBad(make_unique<_filter_IsTradeTickPossiblyBadType>())
   // Constant Components
   , _floatHelper(make_unique<Utils::FloatHelper>())
   , _tradeConditionIdentifierDeterminer(make_unique<TickData::TradeConditionIdentifierDeterminer>())
{
}

BadTradeTicksDeterminer::~BadTradeTicksDeterminer()
{
}

vector<TickData::TradeTick> BadTradeTicksDeterminer::FindPossibleBadTradeTicks(
   const vector<TickData::TradeTick>& tradeTicks, float badTickChangePercentThreshold) const
{
   vector<TickData::TradeTick> possibleBadTradeTicks = _filter_IsTradeTickPossiblyBad->GetMatchingElements(
      tradeTicks,
      this, &BadTradeTicksDeterminer::IsTradeTickPossiblyBad,
      badTickChangePercentThreshold);
   return possibleBadTradeTicks;
}

// Private Functions

bool BadTradeTicksDeterminer::IsTradeTickPossiblyBad(
   const TickData::TradeTick& tradeTick, float badTickChangePercentThreshold) const
{
   const bool isExtendedHoursOrOpeningOrClosingPrice =
      _tradeConditionIdentifierDeterminer->IsExtendedHoursOrOpeningOrClosingPrice(tradeTick.tradeConditionIdentifier);
   if (isExtendedHoursOrOpeningOrClosingPrice)
   {
      return false;
   }
   if (tradeTick.priceChangePercent == FLT_MAX)
   {
      return false;
   }
   bool isTradeTickPossiblyBad = _floatHelper->IsFloatAtOrOutsideRange(
      tradeTick.priceChangePercent,
      -badTickChangePercentThreshold,
      badTickChangePercentThreshold);
   return isTradeTickPossiblyBad;
}
