#include "pch.h"
#include "libCppUtils/Components/FloatingPoint/MetalMock/FloatHelperMock.h"
#include "libFunctional/Components/Filters/Member/MetalMock/TwoArgMemberFunctionFilterMock.h"
#include "libTickData/Components/Determiners/MetalMock/TradeConditionIdentifierDeterminerMock.h"
#include "libTradeTicksAnalyzer/Components/Determiners/BadTradeTicksDeterminer.h"

TESTS(BadTradeTicksDeterminerTests)
AFACT(FindPossibleBadTradeTicks_DoesSo)
// Private Functions
AFACT(IsTradeTickPossiblyBad_IsClosingPriceOrExtendedHoursTradeTick_ReturnsFalse)
AFACT(IsTradeTickPossiblyBad_IsNotClosingPriceOrExtendedHoursTradeTick_PriceDeltaPercentIsFLT_MAX_ReturnsFalse)
AFACT(IsTradeTickPossiblyBad_IsNotClosingPriceOrExtendedHoursTradeTick_PriceDeltaPercentIsNotFLT_MAX_ReturnsTrueIfPriceDeltaPercentIsAtOrOutsideThreshold)
EVIDENCE

BadTradeTicksDeterminer _badTradeTicksDeterminer;
// Function Callers
using _filter_IsTradeTickPossiblyBadMockType = Functional::TwoArgMemberFunctionFilterMock<
   BadTradeTicksDeterminer, TickData::TradeTick, float>;
_filter_IsTradeTickPossiblyBadMockType* _filter_IsTradeTickPossiblyBadMock = nullptr;
// Constant Components
Utils::FloatHelperMock* _floatHelperMock = nullptr;
TickData::TradeConditionIdentifierDeterminerMock* _tradeConditionIdentifierDeterminerMock = nullptr;

STARTUP
{
   // Function Callers
   _badTradeTicksDeterminer._filter_IsTradeTickPossiblyBad.reset(_filter_IsTradeTickPossiblyBadMock = new _filter_IsTradeTickPossiblyBadMockType);
   // Constant Components
   _badTradeTicksDeterminer._floatHelper.reset(_floatHelperMock = new Utils::FloatHelperMock);
   _badTradeTicksDeterminer._tradeConditionIdentifierDeterminer.reset(_tradeConditionIdentifierDeterminerMock = new TickData::TradeConditionIdentifierDeterminerMock);
}

TEST(FindPossibleBadTradeTicks_DoesSo)
{
   const vector<TickData::TradeTick> possibleBadTradeTicks =
      _filter_IsTradeTickPossiblyBadMock->GetMatchingElementsMock.ReturnRandom();

   const vector<TickData::TradeTick> tradeTicks = ZenUnit::RandomVector<TickData::TradeTick>();
   const float badTickChangePercentThreshold = ZenUnit::Random<float>();
   //
   const vector<TickData::TradeTick> returnedPossibleBadTradeTicks =
      _badTradeTicksDeterminer.FindPossibleBadTradeTicks(tradeTicks, badTickChangePercentThreshold);
   //
   METALMOCK(_filter_IsTradeTickPossiblyBadMock->GetMatchingElementsMock.CalledOnceWith(
      tradeTicks,
      &_badTradeTicksDeterminer, &BadTradeTicksDeterminer::IsTradeTickPossiblyBad,
      badTickChangePercentThreshold));
   VECTORS_ARE_EQUAL(possibleBadTradeTicks, returnedPossibleBadTradeTicks);
}

// Private Functions

TEST(IsTradeTickPossiblyBad_IsClosingPriceOrExtendedHoursTradeTick_ReturnsFalse)
{
   _tradeConditionIdentifierDeterminerMock->IsExtendedHoursMock.Return(true);
   const TickData::TradeTick tradeTick = ZenUnit::Random<TickData::TradeTick>();
   const float badTickChangePercentThreshold = ZenUnit::Random<float>();
   //
   const bool isTradeTickPossiblyBad = _badTradeTicksDeterminer.IsTradeTickPossiblyBad(tradeTick, badTickChangePercentThreshold);
   //
   METALMOCK(_tradeConditionIdentifierDeterminerMock->IsExtendedHoursMock.CalledOnceWith(tradeTick.tradeConditionIdentifier));
   IS_FALSE(isTradeTickPossiblyBad);
}

TEST(IsTradeTickPossiblyBad_IsNotClosingPriceOrExtendedHoursTradeTick_PriceDeltaPercentIsFLT_MAX_ReturnsFalse)
{
   _tradeConditionIdentifierDeterminerMock->IsExtendedHoursMock.Return(false);
   TickData::TradeTick tradeTick = ZenUnit::Random<TickData::TradeTick>();
   tradeTick.priceChangePercent = FLT_MAX;
   const float badTickChangePercentThreshold = ZenUnit::Random<float>();
   //
   const bool isTradeTickPossiblyBad = _badTradeTicksDeterminer.IsTradeTickPossiblyBad(tradeTick, badTickChangePercentThreshold);
   //
   METALMOCK(_tradeConditionIdentifierDeterminerMock->IsExtendedHoursMock.CalledOnceWith(tradeTick.tradeConditionIdentifier));
   IS_FALSE(isTradeTickPossiblyBad);
}

TEST(IsTradeTickPossiblyBad_IsNotClosingPriceOrExtendedHoursTradeTick_PriceDeltaPercentIsNotFLT_MAX_ReturnsTrueIfPriceDeltaPercentIsAtOrOutsideThreshold)
{
   _tradeConditionIdentifierDeterminerMock->IsExtendedHoursMock.Return(false);
   const bool isTradeTickPossiblyBad = _floatHelperMock->IsFloatAtOrOutsideRangeMock.ReturnRandom();
   TickData::TradeTick tradeTick = ZenUnit::Random<TickData::TradeTick>();
   tradeTick.priceChangePercent = ZenUnit::RandomNotEqualTo(FLT_MAX);
   const float badTickChangePercentThreshold = ZenUnit::Random<float>();
   //
   const bool returnedIsTradeTickPossiblyBad = _badTradeTicksDeterminer.IsTradeTickPossiblyBad(tradeTick, badTickChangePercentThreshold);
   //
   METALMOCKTHEN(_tradeConditionIdentifierDeterminerMock->IsExtendedHoursMock.CalledOnceWith(tradeTick.tradeConditionIdentifier)).Then(
   METALMOCKTHEN(_floatHelperMock->IsFloatAtOrOutsideRangeMock.CalledOnceWith(
      tradeTick.priceChangePercent,
      -badTickChangePercentThreshold,
      badTickChangePercentThreshold)));
   ARE_EQUAL(isTradeTickPossiblyBad, returnedIsTradeTickPossiblyBad);
}

RUN_TESTS(BadTradeTicksDeterminerTests)
