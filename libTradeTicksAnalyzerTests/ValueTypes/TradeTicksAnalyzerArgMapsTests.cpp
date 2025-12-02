#include "pch.h"
#include "libTradeTicksAnalyzer/ValueTypes/TradeTicksAnalyzerArgMaps.h"
#include "libTradeTicksAnalyzerTests/ValueTypes/ZenUnit/TradeTicksAnalyzerArgMapsEqualizerAndRandom.h"

TESTS(MarketDataGeneratorArgMapsTests)
AFACT(DefaultConstructor_SetsFieldsToDefaultValues)
EVIDENCE

TEST(DefaultConstructor_SetsFieldsToDefaultValues)
{
   const TradeTicksAnalyzerArgMaps defaultTradeTicksAnalyzerArgMaps;
   TradeTicksAnalyzerArgMaps expectedDefaultTradeTicksAnalyzerArgMaps;
   expectedDefaultTradeTicksAnalyzerArgMaps.docoptArgs_program_mode_a = {};
   expectedDefaultTradeTicksAnalyzerArgMaps.docoptArgs_program_mode_b = {};
   ARE_EQUAL(expectedDefaultTradeTicksAnalyzerArgMaps, defaultTradeTicksAnalyzerArgMaps);
}

RUN_TESTS(MarketDataGeneratorArgMapsTests)
