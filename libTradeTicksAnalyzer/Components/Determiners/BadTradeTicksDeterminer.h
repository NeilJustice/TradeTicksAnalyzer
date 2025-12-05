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

   virtual bool IsTradeTickPossiblyBad(
      const TickData::TradeTick& tradeTick, float badTickChangePercentThreshold) const;
};
