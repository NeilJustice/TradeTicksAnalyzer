#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeDeterminer.h"

TESTS(ProgramModeDeterminerTests)
AFACT(DetermineProgramMode_CalculateTradeTickLatencyStatistics)
AFACT(DetermineProgramMode_FindPossibleBadTradeTicks)
AFACT(DetermineProgramMode_Unset)
EVIDENCE

ProgramModeDeterminer _programModeDeterminer;

TEST(DetermineProgramMode_CalculateTradeTickLatencyStatistics)
{
   TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps;
   tradeTicksAnalyzerArgMaps.docoptArgs_calculate_trade_tick_latency_statistics = ZenUnit::RandomNonEmptyOrderedMap<string, docopt::Value>();
   //
   const ProgramMode programMode = _programModeDeterminer.DetermineProgramMode(tradeTicksAnalyzerArgMaps);
   //
   ARE_EQUAL(ProgramMode::CalculateTradeTickLatencyStatistics, programMode);
}

TEST(DetermineProgramMode_FindPossibleBadTradeTicks)
{
   TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps;
   tradeTicksAnalyzerArgMaps.docoptArgs_find_possible_bad_trade_ticks = ZenUnit::RandomNonEmptyOrderedMap<string, docopt::Value>();
   //
   const ProgramMode programMode = _programModeDeterminer.DetermineProgramMode(tradeTicksAnalyzerArgMaps);
   //
   ARE_EQUAL(ProgramMode::FindPossibleBadTradeTicks, programMode);
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
