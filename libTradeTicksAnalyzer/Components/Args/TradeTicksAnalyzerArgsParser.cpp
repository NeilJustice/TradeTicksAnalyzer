#include "pch.h"
#include "libCppUtils/StaticUtilities/Vector.h"
#include "libDateTime/Components/Args/PreamblePrinter.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeDeterminer.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeSpecificArgsParserDispatcher.h"
#include "libTradeTicksAnalyzer/Components/Args/TradeTicksAnalyzerArgsParser.h"

TradeTicksAnalyzerArgsParser::TradeTicksAnalyzerArgsParser()
   // Constant Components
   : _console(make_unique<Time::Console>("TradeTicksAnalyzer"))
   , _docoptParser(make_unique<Time::DocoptParser>())
   , _preamblePrinter(make_unique<Time::PreamblePrinter>())
   , _programModeDeterminer(make_unique<ProgramModeDeterminer>())
   , _programModeSpecificArgsParserDispatcher(make_unique<ProgramModeSpecificArgsParserDispatcher>())
{
}

TradeTicksAnalyzerArgsParser::~TradeTicksAnalyzerArgsParser()
{
}

TradeTicksAnalyzerArgs TradeTicksAnalyzerArgsParser::ParseStringArgs(const vector<string>& stringArgs) const
{
   _preamblePrinter->PrintPreamble(stringArgs, _console.get());

   const map<string, docopt::Value> docoptArgs_program_mode_a =
      _docoptParser->ParseStringArgs(TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_a, stringArgs, false);

   const map<string, docopt::Value> docoptArgs_program_mode_b =
      _docoptParser->ParseStringArgs(TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_b, stringArgs, false);

   const TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps
   {
      docoptArgs_program_mode_a,
      docoptArgs_program_mode_b
   };
   TradeTicksAnalyzerArgs args = _programModeSpecificArgsParserDispatcher->ParseDocoptArgs(tradeTicksAnalyzerArgMaps);
   return args;
}
