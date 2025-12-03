#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/FindPossibleBadBinaryTradeTicksArgsParser.h"

TESTS(FindPossibleBadBinaryTradeTicksArgsParserTests)
AFACT(ParseDocoptArgs_ParsesSetFindPossibleBadTextTradeTicksrgs_ReturnsArgs)
EVIDENCE

FindPossibleBadBinaryTradeTicksArgsParser _findPossibleBadBinaryTradeTicksArgsParser;
// Base Constant Components
Time::DocoptParserMock* p_docoptParserMock = nullptr;

STARTUP
{
   // Base Constant Components
   _findPossibleBadBinaryTradeTicksArgsParser.p_docoptParser.reset(p_docoptParserMock = new Time::DocoptParserMock);
}

TEST(ParseDocoptArgs_ParsesSetFindPossibleBadTextTradeTicksrgs_ReturnsArgs)
{
   const map<string, docopt::Value> docoptArgs = ZenUnit::RandomOrderedMap<string, docopt::Value>();
   //
   const TradeTicksAnalyzerArgs args = _findPossibleBadBinaryTradeTicksArgsParser.ParseDocoptArgs(docoptArgs);
   //
   TradeTicksAnalyzerArgs expectedArgs;
   expectedArgs.programMode = ProgramMode::FindPossibleBadBinaryTradeTicks;
   ARE_EQUAL(expectedArgs, args);
}

RUN_TESTS(FindPossibleBadBinaryTradeTicksArgsParserTests)
