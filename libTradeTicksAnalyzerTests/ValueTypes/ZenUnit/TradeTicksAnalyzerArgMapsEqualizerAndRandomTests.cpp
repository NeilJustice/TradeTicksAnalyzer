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
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgMaps, docoptArgs_program_mode_a, nonEmptyMap);
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgMaps, docoptArgs_program_mode_b, nonEmptyMap);
}

TEST(TestableRandomTradeTicksAnalyzerArgMaps_ReturnsTradeTicksAnalyzerArgMapsWithAllRandomFields)
{
   const TradeTicksAnalyzerArgMaps randomTradeTicksAnalyzerArgMaps = ZenUnit::TestableRandomTradeTicksAnalyzerArgMaps();
   IS_NOT_EMPTY(randomTradeTicksAnalyzerArgMaps.docoptArgs_program_mode_a);
   IS_NOT_EMPTY(randomTradeTicksAnalyzerArgMaps.docoptArgs_program_mode_b);
}

RUN_TESTS(TradeTicksAnalyzerArgMapsEqualizerAndRandomTests)
