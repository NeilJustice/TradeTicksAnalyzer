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
   expectedDefaultTradeTicksAnalyzerArgMaps.docoptArgs_calculate_trade_tick_latency_statistics = {};
   expectedDefaultTradeTicksAnalyzerArgMaps.docoptArgs_find_possible_bad_trade_ticks = {};
   ARE_EQUAL(expectedDefaultTradeTicksAnalyzerArgMaps, defaultTradeTicksAnalyzerArgMaps);
}

RUN_TESTS(MarketDataGeneratorArgMapsTests)
