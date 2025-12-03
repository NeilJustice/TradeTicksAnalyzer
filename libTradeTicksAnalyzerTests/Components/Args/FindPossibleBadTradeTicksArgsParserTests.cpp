#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/FindPossibleBadTradeTicksArgsParser.h"

TESTS(FindPossibleBadTradeTicksArgsParserTests)
AFACT(ParseDocoptArgs_ParsesSetFindPossibleBadTradeTicksrgs_ReturnsArgs)
EVIDENCE

FindPossibleBadTradeTicksArgsParser _findPossibleBadTradeTicksArgsParser;
// Base Constant Components
Time::DocoptParserMock* p_docoptParserMock = nullptr;

STARTUP
{
   // Base Constant Components
   _findPossibleBadTradeTicksArgsParser.p_docoptParser.reset(p_docoptParserMock = new Time::DocoptParserMock);
}

TEST(ParseDocoptArgs_ParsesSetFindPossibleBadTradeTicksrgs_ReturnsArgs)
{
   const fs::path tradingLogsInputFolderPath = p_docoptParserMock->GetRequiredFolderPathWhichMustExistMock.ReturnRandom();

   const Time::Date date = p_docoptParserMock->GetRequiredDateWhichNeedNotBeValidMock.ReturnRandom();

   const unsigned runNumber = p_docoptParserMock->GetRequiredUnsignedMock.ReturnRandom();

   const fs::path outputFolderPath = p_docoptParserMock->GetRequiredFolderPathWhichNeedNotExistMock.ReturnRandom();

   const bool parallel = p_docoptParserMock->GetOptionalBoolMock.ReturnRandom();

   const map<string, docopt::Value> docoptArgs = ZenUnit::RandomOrderedMap<string, docopt::Value>();
   //
   const TradeTicksAnalyzerArgs args = _findPossibleBadTradeTicksArgsParser.ParseDocoptArgs(docoptArgs);
   //
   METALMOCKTHEN(p_docoptParserMock->GetRequiredFolderPathWhichMustExistMock.CalledOnceWith(docoptArgs, "--trading-logs-folder")).Then(
   METALMOCKTHEN(p_docoptParserMock->GetRequiredDateWhichNeedNotBeValidMock.CalledOnceWith(docoptArgs, "--date"))).Then(
   METALMOCKTHEN(p_docoptParserMock->GetRequiredUnsignedMock.CalledOnceWith(docoptArgs, "--run-number"))).Then(
   METALMOCKTHEN(p_docoptParserMock->GetRequiredFolderPathWhichNeedNotExistMock.CalledOnceWith(docoptArgs, "--output-folder"))).Then(
   METALMOCKTHEN(p_docoptParserMock->GetOptionalBoolMock.CalledOnceWith(docoptArgs, "--parallel")));
   TradeTicksAnalyzerArgs expectedArgs;
   expectedArgs.programMode = ProgramMode::FindPossibleBadTradeTicks;
   expectedArgs.tradingLogsInputFolderPath = tradingLogsInputFolderPath;
   expectedArgs.date = date;
   expectedArgs.runNumber = runNumber;
   expectedArgs.outputFolderPath = outputFolderPath;
   expectedArgs.parallel = parallel;
   ARE_EQUAL(expectedArgs, args);
}

RUN_TESTS(FindPossibleBadTradeTicksArgsParserTests)
