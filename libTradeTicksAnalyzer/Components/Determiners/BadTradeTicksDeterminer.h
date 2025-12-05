#pragma once
namespace Functional
{
   template<typename ClassType, typename ElementType, typename Arg2Type>
   class TwoArgMemberFunctionFilter;
}
namespace Utils
{
   class FloatHelper;
}
namespace TickData
{
   class TradeConditionIdentifierDeterminer;
}

class BadTradeTicksDeterminer
{
   friend class BadTradeTicksDeterminerTests;
private:
   // Function Callers
   using _filter_IsTradeTickPossiblyBadType = Functional::TwoArgMemberFunctionFilter<
      BadTradeTicksDeterminer, TickData::TradeTick, float>;
   unique_ptr<const _filter_IsTradeTickPossiblyBadType> _filter_IsTradeTickPossiblyBad;
   // Constant Components
   unique_ptr<const Utils::FloatHelper> _floatHelper;
   unique_ptr<const TickData::TradeConditionIdentifierDeterminer> _tradeConditionIdentifierDeterminer;
public:
   BadTradeTicksDeterminer();
   virtual ~BadTradeTicksDeterminer();

   virtual vector<TickData::TradeTick> FindPossibleBadTradeTicks(
      const vector<TickData::TradeTick>& tradeTicks, float badTickChangePercentThreshold) const;
   // Private Functions
   bool IsTradeTickPossiblyBad(
      const TickData::TradeTick& tradeTick, float badTickChangePercentThreshold) const;
};
