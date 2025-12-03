#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeBArgsParser.h"

TESTS(ProgramModeBArgsParserTests)
AFACT(ParseDocoptArgs_ParsesSetFindPossibleBadTradeTicksrgs_ReturnsArgs)
EVIDENCE

ProgramModeBArgsParser _programModeBArgsParser;
// Base Constant Components
Time::DocoptParserMock* p_docoptParserMock = nullptr;

STARTUP
{
   // Base Constant Components
   _programModeBArgsParser.p_docoptParser.reset(p_docoptParserMock = new Time::DocoptParserMock);
}

TEST(ParseDocoptArgs_ParsesSetFindPossibleBadTradeTicksrgs_ReturnsArgs)
{
   const map<string, docopt::Value> docoptArgs = ZenUnit::RandomOrderedMap<string, docopt::Value>();
   //
   const TradeTicksAnalyzerArgs args = _programModeBArgsParser.ParseDocoptArgs(docoptArgs);
   //
   TradeTicksAnalyzerArgs expectedArgs;
   expectedArgs.programMode = ProgramMode::ProgramModeB;
   ARE_EQUAL(expectedArgs, args);
}

RUN_TESTS(ProgramModeBArgsParserTests)
