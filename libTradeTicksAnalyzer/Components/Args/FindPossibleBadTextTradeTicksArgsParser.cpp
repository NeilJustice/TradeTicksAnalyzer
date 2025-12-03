#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/FindPossibleBadTextTradeTicksArgsParser.h"

FindPossibleBadTextTradeTicksArgsParser::FindPossibleBadTextTradeTicksArgsParser()
{
}

FindPossibleBadTextTradeTicksArgsParser::~FindPossibleBadTextTradeTicksArgsParser()
{
}

TradeTicksAnalyzerArgs FindPossibleBadTextTradeTicksArgsParser::ParseDocoptArgs(const map<string, docopt::Value>& docoptArgs) const
{
   TradeTicksAnalyzerArgs args;
   args.programMode = ProgramMode::FindPossibleBadTextTradeTicks;
   args.tradingLogsInputFolderPath = p_docoptParser->GetRequiredFolderPathWhichMustExist(docoptArgs, "--trading-logs-folder");
   args.dateWithDayOfWeek = p_docoptParser->GetRequiredDateWithDayOfWeekWhichNeedNotBeValid(docoptArgs, "--date");
   args.runNumber = p_docoptParser->GetRequiredUnsigned(docoptArgs, "--run-number");
   args.tradingLogsOutputFolderPath = p_docoptParser->GetRequiredFolderPathWhichNeedNotExist(docoptArgs, "--output-folder");
   args.parallel = p_docoptParser->GetOptionalBool(docoptArgs, "--parallel");
   // Calculated Fields

   return args;
}
