#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeDeterminer.h"

ProgramModeDeterminer::ProgramModeDeterminer()
   // Constant Components
   : _docoptParser(make_unique<Time::DocoptParser>())
{
}

ProgramModeDeterminer::~ProgramModeDeterminer()
{
}

ProgramMode ProgramModeDeterminer::DetermineProgramMode(const TradeTicksAnalyzerArgMaps& tradeTicksAnalyzerArgMaps) const
{
   if (!tradeTicksAnalyzerArgMaps.docoptArgs_calculate_trade_tick_latency_statistics.empty())
   {
      return ProgramMode::ProgramModeA;
   }
   if (!tradeTicksAnalyzerArgMaps.docoptArgs_find_possible_bad_trade_ticks.empty())
   {
      return ProgramMode::ProgramModeB;
   }
   return ProgramMode::Invalid;
}
