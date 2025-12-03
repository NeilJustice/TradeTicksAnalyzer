#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeDeterminer.h"

TESTS(ProgramModeDeterminerTests)
AFACT(DetermineProgramMode_FindPossibleBadBinaryTradeTicks)
AFACT(DetermineProgramMode_FindPossibleBadTextTradeTicks)
AFACT(DetermineProgramMode_Unset)
EVIDENCE

ProgramModeDeterminer _programModeDeterminer;

TEST(DetermineProgramMode_FindPossibleBadBinaryTradeTicks)
{
   TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps;
   tradeTicksAnalyzerArgMaps.docoptArgs_calculate_trade_tick_latency_statistics = ZenUnit::RandomNonEmptyOrderedMap<string, docopt::Value>();
   //
   const ProgramMode programMode = _programModeDeterminer.DetermineProgramMode(tradeTicksAnalyzerArgMaps);
   //
   ARE_EQUAL(ProgramMode::FindPossibleBadBinaryTradeTicks, programMode);
}

TEST(DetermineProgramMode_FindPossibleBadTextTradeTicks)
{
   TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps;
   tradeTicksAnalyzerArgMaps.docoptArgs_find_possible_bad_trade_ticks = ZenUnit::RandomNonEmptyOrderedMap<string, docopt::Value>();
   //
   const ProgramMode programMode = _programModeDeterminer.DetermineProgramMode(tradeTicksAnalyzerArgMaps);
   //
   ARE_EQUAL(ProgramMode::FindPossibleBadTextTradeTicks, programMode);
}

TEST(DetermineProgramMode_Unset)
{
   TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps;
   //
   const ProgramMode programMode = _programModeDeterminer.DetermineProgramMode(tradeTicksAnalyzerArgMaps);
   //
   ARE_EQUAL(ProgramMode::Invalid, programMode);
}

RUN_TESTS(ProgramModeDeterminerTests)
