#pragma once
#include "libTradeTicksAnalyzer/ValueTypes/TradeTicksAnalyzerArgMaps.h"

namespace ZenUnit
{
   template<>
   class Equalizer<TradeTicksAnalyzerArgMaps>
   {
   public:
      static void AssertEqual(
         const TradeTicksAnalyzerArgMaps& expectedTradeTicksAnalyzerArgMaps,
         const TradeTicksAnalyzerArgMaps& actualTradeTicksAnalyzerArgMaps);
   };

   TradeTicksAnalyzerArgMaps TestableRandomTradeTicksAnalyzerArgMaps();

   template<>
   TradeTicksAnalyzerArgMaps Random();
}
