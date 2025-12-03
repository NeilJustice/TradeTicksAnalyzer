#pragma once
#include "libTradeTicksAnalyzer/ValueTypes/TradeTicksAnalyzerArgs.h"
#include "libTradeTicksAnalyzerTests/Components/Testing/TradeTicksAnalyzerRandomGenerator.h"
namespace Time
{
   class TimeRandomGenerator;
}

namespace ZenUnit
{
   template<>
   struct Equalizer<TradeTicksAnalyzerArgs>
   {
      static void AssertEqual(
         const TradeTicksAnalyzerArgs& expectedTradeTicksAnalyzerArgs, const TradeTicksAnalyzerArgs& actualTradeTicksAnalyzerArgs);
   };

   TradeTicksAnalyzerArgs TestableRandomTradeTicksAnalyzerArgs(
      const RandomGenerator* randomGenerator,
      const Time::TimeRandomGenerator* timeRandomGenerator,
      const TradeTicksAnalyzerRandomGenerator* tradeTicksAnalyzerRandomGenerator);

   template<>
   TradeTicksAnalyzerArgs Random();
}
