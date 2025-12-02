#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeAArgsParser.h"

TESTS(ProgramModeAArgsParserTests)
AFACT(ParseDocoptArgs_ParsesSetProgramModeArgs_ReturnsArgs)
EVIDENCE

ProgramModeAArgsParser _programModeAArgsParser;
// Base Constant Components
Time::DocoptParserMock* p_docoptParserMock = nullptr;

STARTUP
{
   // Base Constant Components
   _programModeAArgsParser.p_docoptParser.reset(p_docoptParserMock = new Time::DocoptParserMock);
}

TEST(ParseDocoptArgs_ParsesSetProgramModeArgs_ReturnsArgs)
{
   const string requiredString = p_docoptParserMock->GetRequiredStringMock.ReturnRandom();

   const bool parallel = p_docoptParserMock->GetOptionalBoolMock.ReturnRandom();

   const map<string, docopt::Value> docoptArgs = ZenUnit::RandomOrderedMap<string, docopt::Value>();
   //
   const TradeTicksAnalyzerArgs args = _programModeAArgsParser.ParseDocoptArgs(docoptArgs);
   //
   METALMOCKTHEN(p_docoptParserMock->GetRequiredStringMock.CalledOnceWith(docoptArgs, "--required-string")).Then(
   METALMOCKTHEN(p_docoptParserMock->GetOptionalBoolMock.CalledOnceWith(docoptArgs, "--parallel")));
   TradeTicksAnalyzerArgs expectedArgs;
   expectedArgs.programMode = ProgramMode::ProgramModeA;
   expectedArgs.requiredString = requiredString;
   expectedArgs.parallel = parallel;
   ARE_EQUAL(expectedArgs, args);
}

RUN_TESTS(ProgramModeAArgsParserTests)
