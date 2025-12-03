#include "pch.h"
#include "libTradeTicksAnalyzerTests/ValueTypes/ZenUnit/TradeTicksAnalyzerArgMapsEqualizerAndRandom.h"

namespace ZenUnit
{
   void Equalizer<TradeTicksAnalyzerArgMaps>::AssertEqual(
      const TradeTicksAnalyzerArgMaps& expectedTradeTicksAnalyzerArgMaps,
      const TradeTicksAnalyzerArgMaps& actualTradeTicksAnalyzerArgMaps)
   {
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgMaps, actualTradeTicksAnalyzerArgMaps, docoptArgs_calculate_trade_tick_latency_statistics);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgMaps, actualTradeTicksAnalyzerArgMaps, docoptArgs_find_possible_bad_trade_ticks);
   }

   TradeTicksAnalyzerArgMaps TestableRandomTradeTicksAnalyzerArgMaps()
   {
      TradeTicksAnalyzerArgMaps randomTradeTicksAnalyzerArgMaps;
      randomTradeTicksAnalyzerArgMaps.docoptArgs_calculate_trade_tick_latency_statistics[ZenUnit::Random<string>()] = docopt::Value{};
      randomTradeTicksAnalyzerArgMaps.docoptArgs_find_possible_bad_trade_ticks[ZenUnit::Random<string>()] = docopt::Value{};
      return randomTradeTicksAnalyzerArgMaps;
   }

   template<>
   TradeTicksAnalyzerArgMaps Random()
   {
      return TestableRandomTradeTicksAnalyzerArgMaps();
   }
}
