#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeDeterminer.h"

TESTS(ProgramModeDeterminerTests)
AFACT(DetermineProgramMode_ProgramModeA)
AFACT(DetermineProgramMode_ProgramModeB)
AFACT(DetermineProgramMode_Unset)
EVIDENCE

ProgramModeDeterminer _programModeDeterminer;

TEST(DetermineProgramMode_ProgramModeA)
{
   TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps;
   tradeTicksAnalyzerArgMaps.docoptArgs_calculate_trade_tick_latencies = ZenUnit::RandomNonEmptyOrderedMap<string, docopt::Value>();
   //
   const ProgramMode programMode = _programModeDeterminer.DetermineProgramMode(tradeTicksAnalyzerArgMaps);
   //
   ARE_EQUAL(ProgramMode::ProgramModeA, programMode);
}

TEST(DetermineProgramMode_ProgramModeB)
{
   TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps;
   tradeTicksAnalyzerArgMaps.docoptArgs_find_possible_bad_trade_ticks = ZenUnit::RandomNonEmptyOrderedMap<string, docopt::Value>();
   //
   const ProgramMode programMode = _programModeDeterminer.DetermineProgramMode(tradeTicksAnalyzerArgMaps);
   //
   ARE_EQUAL(ProgramMode::ProgramModeB, programMode);
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
