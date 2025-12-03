#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/CalculateTradeTickLatencyStatisticsArgsParser.h"

TESTS(CalculateTradeTickLatencyStatisticsArgsParserTests)
AFACT(ParseDocoptArgs_ParsesSetFindPossibleBadTextTradeTicksrgs_ReturnsArgs)
EVIDENCE

CalculateTradeTickLatencyStatisticsArgsParser _calculateTradeTickLatencyStatisticsArgsParser;
// Base Constant Components
Time::DocoptParserMock* p_docoptParserMock = nullptr;

STARTUP
{
   // Base Constant Components
   _calculateTradeTickLatencyStatisticsArgsParser.p_docoptParser.reset(p_docoptParserMock = new Time::DocoptParserMock);
}

TEST(ParseDocoptArgs_ParsesSetFindPossibleBadTextTradeTicksrgs_ReturnsArgs)
{
   const map<string, docopt::Value> docoptArgs = ZenUnit::RandomOrderedMap<string, docopt::Value>();
   //
   const TradeTicksAnalyzerArgs args = _calculateTradeTickLatencyStatisticsArgsParser.ParseDocoptArgs(docoptArgs);
   //
   TradeTicksAnalyzerArgs expectedArgs;
   expectedArgs.programMode = ProgramMode::CalculateTradeTickLatencyStatistics;
   ARE_EQUAL(expectedArgs, args);
}

RUN_TESTS(CalculateTradeTickLatencyStatisticsArgsParserTests)
