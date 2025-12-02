#include "pch.h"
#include "libTradeTicksAnalyzerTests/ValueTypes/ZenUnit/TradeTicksAnalyzerArgMapsEqualizerAndRandom.h"

namespace ZenUnit
{
   void Equalizer<TradeTicksAnalyzerArgMaps>::AssertEqual(
      const TradeTicksAnalyzerArgMaps& expectedTradeTicksAnalyzerArgMaps,
      const TradeTicksAnalyzerArgMaps& actualTradeTicksAnalyzerArgMaps)
   {
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgMaps, actualTradeTicksAnalyzerArgMaps, docoptArgs_program_mode_a);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgMaps, actualTradeTicksAnalyzerArgMaps, docoptArgs_program_mode_b);
   }

   TradeTicksAnalyzerArgMaps TestableRandomTradeTicksAnalyzerArgMaps()
   {
      TradeTicksAnalyzerArgMaps randomTradeTicksAnalyzerArgMaps;
      randomTradeTicksAnalyzerArgMaps.docoptArgs_program_mode_a[ZenUnit::Random<string>()] = docopt::Value{};
      randomTradeTicksAnalyzerArgMaps.docoptArgs_program_mode_b[ZenUnit::Random<string>()] = docopt::Value{};
      return randomTradeTicksAnalyzerArgMaps;
   }

   template<>
   TradeTicksAnalyzerArgMaps Random()
   {
      return TestableRandomTradeTicksAnalyzerArgMaps();
   }
}
