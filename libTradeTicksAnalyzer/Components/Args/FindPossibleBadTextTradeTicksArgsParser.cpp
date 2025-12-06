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
   args.tradingLogsInputFolderPath = p_docoptParser->GetRequiredFolderPathWhichMustExist(docoptArgs, "--trading-logs-input-folder");
   args.dateWithDayOfWeek = p_docoptParser->GetRequiredDateWithDayOfWeekWhichNeedNotBeValid(docoptArgs, "--date");
   args.runNumber = p_docoptParser->GetRequiredUnsigned(docoptArgs, "--run-number");
   args.badTickChangePercentThreshold = p_docoptParser->GetRequiredFloat(docoptArgs, "--bad-tick-change-percent-threshold");
   args.tradingLogsOutputFolderPath = p_docoptParser->GetRequiredFolderPathWhichNeedNotExist(docoptArgs, "--trading-logs-output-folder");
   args.parallel = p_docoptParser->GetOptionalBool(docoptArgs, "--parallel");
   // Calculated Fields
   const string dateDashRunNumberFolderName = Utils::String::ConcatValues(args.dateWithDayOfWeek, "-", args.runNumber);
   args.tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks =
      p_fileSystemPather->MakeThreeDeepFolderPathWhichMustExist(
         args.tradingLogsInputFolderPath, dateDashRunNumberFolderName, "Polygon", "FilteredRealTimeTextTradeTicks");

   args.tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBad =
      p_fileSystemPather->MakeThreeDeepFolderPathWhichNeedNotExist(
         args.tradingLogsOutputFolderPath, dateDashRunNumberFolderName, "Polygon", "FilteredRealTimeTextTradeTicks-PossibleBad");
   return args;
}
