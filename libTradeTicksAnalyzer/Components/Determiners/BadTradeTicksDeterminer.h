#pragma once
namespace Utils
{
   class FloatHelper;
}

class BadTradeTicksDeterminer
{
   friend class BadTradeTicksDeterminerTests;
private:
   // Constant Components
   unique_ptr<const Utils::FloatHelper> _floatHelper;
public:
   BadTradeTicksDeterminer();
   virtual ~BadTradeTicksDeterminer();

   virtual vector<TickData::TradeTick> FindPossibleBadTradeTicks(
      const vector<TickData::TradeTick>& tradeTicks, float badTickChangePercentThreshold) const;
   // Private Functions
   bool IsTradeTickPossiblyBad(
      const TickData::TradeTick& tradeTick, float badTickChangePercentThreshold) const;
};
