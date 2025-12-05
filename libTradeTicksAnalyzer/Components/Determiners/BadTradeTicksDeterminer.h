#pragma once

class BadTradeTicksDeterminer
{
   friend class BadTradeTicksDeterminerTests;
private:
   // Constant Components

public:
   BadTradeTicksDeterminer();
   virtual ~BadTradeTicksDeterminer();

   virtual bool IsTradeTickPossiblyBad(
      const TickData::TradeTick& tradeTick, float badTickChangePercentThreshold) const;
};
