#pragma once
#include "libTradeTicksAnalyzer/ValueTypes/TradeTicksAnalyzerArgs.h"
#include "libTradeTicksAnalyzerTests/Components/Testing/TradeTicksAnalyzerRandomGenerator.h"

namespace ZenUnit
{
   template<>
   struct Equalizer<TradeTicksAnalyzerArgs>
   {
      static void AssertEqual(
         const TradeTicksAnalyzerArgs& expectedTradeTicksAnalyzerArgs, const TradeTicksAnalyzerArgs& actualTradeTicksAnalyzerArgs);
   };

   TradeTicksAnalyzerArgs TestableRandomTradeTicksAnalyzerArgs(
      const RandomGenerator* randomGenerator, const TradeTicksAnalyzerRandomGenerator* tradeTicksAnalyzerRandomGenerator);

   template<>
   TradeTicksAnalyzerArgs Random();
}
