#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/FindPossibleBadTextTradeTicksArgsParser.h"
#include "libTradeTicksAnalyzer/Components/Args/CalculateTradeTickLatencyStatisticsArgsParser.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeDeterminer.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeSpecificArgsParserDispatcher.h"

ProgramModeSpecificArgsParserDispatcher::ProgramModeSpecificArgsParserDispatcher()
   // Constant Components
   : _findPossibleBadTextTradeTicksArgsParser(make_unique<FindPossibleBadTextTradeTicksArgsParser>())
   , _calculateTradeTickLatencyStatisticsArgsParser(make_unique<CalculateTradeTickLatencyStatisticsArgsParser>())
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
   case ProgramMode::CalculateTradeTickLatencyStatistics:
   {
      args = _calculateTradeTickLatencyStatisticsArgsParser->ParseDocoptArgs(
         tradeTicksAnalyzerArgMaps.docoptArgs_calculate_trade_tick_latency_statistics);
      break;
   }
   case ProgramMode::FindPossibleBadTextTradeTicks:
   {
      args = _findPossibleBadTextTradeTicksArgsParser->ParseDocoptArgs(
         tradeTicksAnalyzerArgMaps.docoptArgs_find_possible_bad_trade_ticks);
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
