#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/FindPossibleBadTextTradeTicksArgsParser.h"

TESTS(FindPossibleBadTextTradeTicksArgsParserTests)
AFACT(ParseDocoptArgs_ParsesSetFindPossibleBadTextTradeTicksrgs_ReturnsArgs)
EVIDENCE

FindPossibleBadTextTradeTicksArgsParser _findPossibleBadTextTradeTicksArgsParser;
// Base Constant Components
Time::DocoptParserMock* p_docoptParserMock = nullptr;

STARTUP
{
   // Base Constant Components
   _findPossibleBadTextTradeTicksArgsParser.p_docoptParser.reset(p_docoptParserMock = new Time::DocoptParserMock);
}

TEST(ParseDocoptArgs_ParsesSetFindPossibleBadTextTradeTicksrgs_ReturnsArgs)
{
   const fs::path tradingLogsInputFolderPath = p_docoptParserMock->GetRequiredFolderPathWhichMustExistMock.ReturnRandom();

   const Time::DateWithDayOfWeek dateWithDayOfWeek = p_docoptParserMock->GetRequiredDateWithDayOfWeekWhichNeedNotBeValidMock.ReturnRandom();

   const unsigned runNumber = p_docoptParserMock->GetRequiredUnsignedMock.ReturnRandom();

   const fs::path tradingLogsOutputFolderPath = p_docoptParserMock->GetRequiredFolderPathWhichNeedNotExistMock.ReturnRandom();

   const bool parallel = p_docoptParserMock->GetOptionalBoolMock.ReturnRandom();

   const map<string, docopt::Value> docoptArgs = ZenUnit::RandomOrderedMap<string, docopt::Value>();
   //
   const TradeTicksAnalyzerArgs args = _findPossibleBadTextTradeTicksArgsParser.ParseDocoptArgs(docoptArgs);
   //
   METALMOCKTHEN(p_docoptParserMock->GetRequiredFolderPathWhichMustExistMock.CalledOnceWith(docoptArgs, "--trading-logs-input-folder")).Then(
   METALMOCKTHEN(p_docoptParserMock->GetRequiredDateWithDayOfWeekWhichNeedNotBeValidMock.CalledOnceWith(docoptArgs, "--date"))).Then(
   METALMOCKTHEN(p_docoptParserMock->GetRequiredUnsignedMock.CalledOnceWith(docoptArgs, "--run-number"))).Then(
   METALMOCKTHEN(p_docoptParserMock->GetRequiredFolderPathWhichNeedNotExistMock.CalledOnceWith(docoptArgs, "--trading-logs-output-folder"))).Then(
   METALMOCKTHEN(p_docoptParserMock->GetOptionalBoolMock.CalledOnceWith(docoptArgs, "--parallel")));
   TradeTicksAnalyzerArgs expectedArgs;
   expectedArgs.programMode = ProgramMode::FindPossibleBadTextTradeTicks;
   expectedArgs.tradingLogsInputFolderPath = tradingLogsInputFolderPath;
   expectedArgs.dateWithDayOfWeek = dateWithDayOfWeek;
   expectedArgs.runNumber = runNumber;
   expectedArgs.tradingLogsOutputFolderPath = tradingLogsOutputFolderPath;
   expectedArgs.parallel = parallel;
   ARE_EQUAL(expectedArgs, args);
}

RUN_TESTS(FindPossibleBadTextTradeTicksArgsParserTests)
