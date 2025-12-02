#include "pch.h"
#include "libTradeTicksAnalyzerTests/ValueTypes/ZenUnit/TradeTicksAnalyzerArgMapsEqualizerAndRandom.h"

TESTS(TradeTicksAnalyzerArgMapsEqualizerAndRandomTests)
AFACT(ZenUnitEqualizer_ThrowsZenUnitAnomalyIfAnyFieldNotEqual)
AFACT(TestableRandomTradeTicksAnalyzerArgMaps_ReturnsTradeTicksAnalyzerArgMapsWithAllRandomFields)
EVIDENCE

TEST(ZenUnitEqualizer_ThrowsZenUnitAnomalyIfAnyFieldNotEqual)
{
   ZENUNIT_EQUALIZER_TEST_SETUP(TradeTicksAnalyzerArgMaps);
   const map<string, docopt::Value> nonEmptyMap = ZenUnit::RandomNonEmptyOrderedMap<string, docopt::Value>();
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgMaps, docoptArgs_calculate_trade_tick_latencies, nonEmptyMap);
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgMaps, docoptArgs_find_possible_bad_trade_ticks, nonEmptyMap);
}

TEST(TestableRandomTradeTicksAnalyzerArgMaps_ReturnsTradeTicksAnalyzerArgMapsWithAllRandomFields)
{
   const TradeTicksAnalyzerArgMaps randomTradeTicksAnalyzerArgMaps = ZenUnit::TestableRandomTradeTicksAnalyzerArgMaps();
   IS_NOT_EMPTY(randomTradeTicksAnalyzerArgMaps.docoptArgs_calculate_trade_tick_latencies);
   IS_NOT_EMPTY(randomTradeTicksAnalyzerArgMaps.docoptArgs_find_possible_bad_trade_ticks);
}

RUN_TESTS(TradeTicksAnalyzerArgMapsEqualizerAndRandomTests)
