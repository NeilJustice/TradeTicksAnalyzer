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
   if (!tradeTicksAnalyzerArgMaps.docoptArgs_program_mode_a.empty())
   {
      return ProgramMode::ProgramModeA;
   }
   if (!tradeTicksAnalyzerArgMaps.docoptArgs_program_mode_b.empty())
   {
      return ProgramMode::ProgramModeB;
   }
   return ProgramMode::Invalid;
}
