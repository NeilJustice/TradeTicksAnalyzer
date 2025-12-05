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

bool BadTradeTicksDeterminer::IsTradeTickPossiblyBad(
   const TickData::TradeTick& /*tradeTick*/, float /*badTickChangePercentThreshold*/) const
{
   return false;
}
