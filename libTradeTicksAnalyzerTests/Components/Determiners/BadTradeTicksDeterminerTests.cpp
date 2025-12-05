#include "pch.h"
#include "libCppUtils/Components/FloatingPoint/MetalMock/FloatHelperMock.h"
#include "libTradeTicksAnalyzer/Components/Determiners/BadTradeTicksDeterminer.h"

TESTS(BadTradeTicksDeterminerTests)
AFACT(IsTradeTickPossiblyBad_TradeTickIsPremarketOrAftermarket_ReturnsFalse)
AFACT(IsTradeTickPossiblyBad_TradeTickIsRegularHours_ChangePercentWithinBounds_ReturnsFalse)
AFACT(IsTradeTickPossiblyBad_TradeTickIsRegularHours_ChangePercentAtOrOutOfBounds_ReturnsTrue)
EVIDENCE

BadTradeTicksDeterminer _badTradeTicksDeterminer;
// Constant Components
Utils::FloatHelperMock* _floatHelperMock = nullptr;

STARTUP
{
   // Constant Components
   _badTradeTicksDeterminer._floatHelper.reset(_floatHelperMock = new Utils::FloatHelperMock);
}

TEST(IsTradeTickPossiblyBad_TradeTickIsPremarketOrAftermarket_ReturnsFalse)
{

   const TickData::TradeTick tradeTick = ZenUnit::Random<TickData::TradeTick>();
   const float badTickChangePercentThreshold = ZenUnit::Random<float>();
   //
   const bool isTradeTickPossiblyBad = _badTradeTicksDeterminer.IsTradeTickPossiblyBad(tradeTick, badTickChangePercentThreshold);
   //

   IS_FALSE(isTradeTickPossiblyBad);
}

TEST(IsTradeTickPossiblyBad_TradeTickIsRegularHours_ChangePercentWithinBounds_ReturnsFalse)
{

   const TickData::TradeTick tradeTick = ZenUnit::Random<TickData::TradeTick>();
   const float badTickChangePercentThreshold = ZenUnit::Random<float>();
   //
   const bool isTradeTickPossiblyBad = _badTradeTicksDeterminer.IsTradeTickPossiblyBad(tradeTick, badTickChangePercentThreshold);
   //

   IS_FALSE(isTradeTickPossiblyBad);
}

TEST(IsTradeTickPossiblyBad_TradeTickIsRegularHours_ChangePercentAtOrOutOfBounds_ReturnsTrue)
{

   const TickData::TradeTick tradeTick = ZenUnit::Random<TickData::TradeTick>();
   const float badTickChangePercentThreshold = ZenUnit::Random<float>();
   //
   const bool isTradeTickPossiblyBad = _badTradeTicksDeterminer.IsTradeTickPossiblyBad(tradeTick, badTickChangePercentThreshold);
   //

   IS_FALSE(isTradeTickPossiblyBad);
}

RUN_TESTS(BadTradeTicksDeterminerTests)
