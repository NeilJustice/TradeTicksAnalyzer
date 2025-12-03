#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeAArgsParser.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeBArgsParser.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeDeterminer.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeSpecificArgsParserDispatcher.h"

ProgramModeSpecificArgsParserDispatcher::ProgramModeSpecificArgsParserDispatcher()
   // Constant Components
   : _programModeAArgsParser(make_unique<ProgramModeAArgsParser>())
   , _programModeBArgsParser(make_unique<ProgramModeBArgsParser>())
   , _programModeDeterminer(make_unique<ProgramModeDeterminer>())
{
}

ProgramModeSpecificArgsParserDispatcher::~ProgramModeSpecificArgsParserDispatcher()
{
}

TradeTicksAnalyzerArgs ProgramModeSpecificArgsParserDispatcher::ParseDocoptArgs(const TradeTicksAnalyzerArgMaps& tradeTicksAnalyzerArgMaps) const
{
   const ProgramMode programMode = _programModeDeterminer->DetermineProgramMode(tradeTicksAnalyzerArgMaps);
   TradeTicksAnalyzerArgs args;
   switch (programMode)
   {
   case ProgramMode::ProgramModeA:
   {
      args = _programModeAArgsParser->ParseDocoptArgs(tradeTicksAnalyzerArgMaps.docoptArgs_calculate_trade_tick_latency_statistics);
      break;
   }
   case ProgramMode::ProgramModeB:
   {
      args = _programModeBArgsParser->ParseDocoptArgs(tradeTicksAnalyzerArgMaps.docoptArgs_find_possible_bad_trade_ticks);
      break;
   }
   default:
   {
      const string exceptionMessage = Utils::String::ConcatStrings(
         "Invalid command line usage.\n\n", TradeTicksAnalyzerArgs::CommandLineUsage);
      throw invalid_argument(exceptionMessage);
   }
   }
   return args;
}
