#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/FindPossibleBadTradeTicksArgsParser.h"

FindPossibleBadTradeTicksArgsParser::FindPossibleBadTradeTicksArgsParser()
{
}

FindPossibleBadTradeTicksArgsParser::~FindPossibleBadTradeTicksArgsParser()
{
}

TradeTicksAnalyzerArgs FindPossibleBadTradeTicksArgsParser::ParseDocoptArgs(const map<string, docopt::Value>& docoptArgs) const
{
   TradeTicksAnalyzerArgs args;
   args.programMode = ProgramMode::FindPossibleBadTradeTicks;
   args.tradingLogsInputFolderPath = p_docoptParser->GetRequiredFolderPathWhichMustExist(docoptArgs, "--trading-logs-folder");
   args.date = p_docoptParser->GetRequiredDateWhichNeedNotBeValid(docoptArgs, "--date");
   args.runNumber = p_docoptParser->GetRequiredUnsigned(docoptArgs, "--run-number");
   args.outputFolderPath = p_docoptParser->GetRequiredFolderPathWhichNeedNotExist(docoptArgs, "--output-folder");
   args.parallel = p_docoptParser->GetOptionalBool(docoptArgs, "--parallel");
   return args;
}
